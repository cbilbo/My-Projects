minikube --driver=virtualbox --memory='3000' --disk-size 40000MB start 

minikube addons enable metallb
minikube addons enable metrics-server
minikube addons enable dashboard

eval $(minikube docker-env)

cd srcs/

bash dockerstart.sh
bash kuberstart.sh
sleep 10

kubectl get pods