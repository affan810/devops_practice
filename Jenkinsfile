pipeline {
    agent any

    environment {
        PATH+EXTRA = "/usr/local/bin:/opt/homebrew/bin"
        IMAGE_NAME = "affan810/scientific-calculator"
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
                sh 'docker build -t scientific-calculator .'
            }
        }

        stage('Docker Push') {
            steps {
                echo "Pushing image to Docker Hub..."

                withCredentials([
                    usernamePassword(
                        credentialsId: 'dockerhub-creds',
                        usernameVariable: 'DOCKER_USER',
                        passwordVariable: 'DOCKER_PASS'
                    )
                ]) {

                    sh '''
                    echo "$DOCKER_PASS" | docker login -u "$DOCKER_USER" --password-stdin

                    docker tag scientific-calculator $IMAGE_NAME:latest
                    docker tag scientific-calculator $IMAGE_NAME:$BUILD_NUMBER

                    docker push $IMAGE_NAME:latest
                    docker push $IMAGE_NAME:$BUILD_NUMBER

                    docker logout
                    '''
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
            emailext(
                subject: "Jenkins Pipeline SUCCESS",
                body: """
Build Successful!

Job: ${env.JOB_NAME}
Build Number: ${env.BUILD_NUMBER}
Build URL: ${env.BUILD_URL}
""",
                to: "shaikhaffan810@gmail.com"
            )
        }

        failure {
            emailext(
                subject: "Jenkins Pipeline FAILED",
                body: """
Build Failed!

Job: ${env.JOB_NAME}
Build Number: ${env.BUILD_NUMBER}

Check logs here:
${env.BUILD_URL}
""",
                to: "shaikhaffan810@gmail.com"
            )
        }
    }
}