pipeline {
    agent any

    environment {
        PATH = "/opt/homebrew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"
    }

    stages {

        stage('Build Calculator') {
            steps {
                echo "Building calculator..."
                sh 'make build'
            }
        }

        stage('Test Calculator') {
            steps {
                echo "Running tests..."
                sh 'make test'
            }
        }

        stage('Docker Build') {
            steps {
                echo "Building Docker image..."
                sh '/opt/homebrew/bin/docker build -t scientific-calculator .'
            }
        }

        stage('Docker Push') {
            steps {
                echo "Pushing image to Docker Hub..."

                withCredentials([usernamePassword(
                    credentialsId: 'dockerhub-credentials',
                    usernameVariable: 'DOCKER_USER',
                    passwordVariable: 'DOCKER_PASS'
                )]) {

                    sh 'echo $DOCKER_PASS | /opt/homebrew/bin/docker login -u $DOCKER_USER --password-stdin'
                    sh '/opt/homebrew/bin/docker tag scientific-calculator 3piradians/scientific-calculator:latest'
                    sh '/opt/homebrew/bin/docker push 3piradians/scientific-calculator:latest'
                }
            }
        }

        stage('Deploy Calculator') {
            steps {
                echo "Deploying container using Ansible..."
                sh 'ansible-playbook -i ansible/hosts ansible/deploy.yml'
            }
        }
    }

post {

    success {
        emailext (
            subject: "Jenkins Pipeline SUCCESS",
            body: """
                Build Successful!

                Job: ${env.JOB_NAME}
                Build Number: ${env.BUILD_NUMBER}
                Build URL: ${env.BUILD_URL}
                """,
            to: "pankajdeopa@gmail.com"
        )
    }

    failure {
        emailext (
            subject: "Jenkins Pipeline FAILED",
            body: """
                    Build Failed!

                    Job: ${env.JOB_NAME}
                    Build Number: ${env.BUILD_NUMBER}

                    Check logs here:
                    ${env.BUILD_URL}
                """,
            to: "pankajdeopa@gmail.com"
        )
    }
}
}