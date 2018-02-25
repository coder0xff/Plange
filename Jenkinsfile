pipeline {
	agent any

  environment {
		CMAKE_DIR = '/usr/local/bin'
	}

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
							${CMAKE_DIR}/cmake .. &&
							make
					 '''
			}
		}
	}
}
