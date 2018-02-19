pipeline {
	agent any

	stages {
		stage('Clone') {
			steps {
				checkout scm
				sh 'mkdir -p Plange.build'
			}
		}

		stage('Build') {
			steps {
				sh '''
				      cd Plange.build &&
				      rm -rf * && 
							cmake --version &&
							cmake .. &&
							make
					 '''
			}
		}
	}
}
