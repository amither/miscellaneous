#!/bin/bash
set -e
usage () {
    echo -e "Usage: $0 [-t tag] [-p]"
    echo -e "\t -t \t image tag,  e.g. v0.1"
    echo -e "\t -p \t push image to tcloud private registroy"
}

[ $# -lt 1 ] && usage && exit 1

tag=""
while getopts "t:p" arg; do
    case $arg in
    t) tag=${OPTARG} ;;
    p) is_push=true ;;
    h|?) usage; exit 2; ;;
    esac
done

[ ${tag} == "" ] && echo "-t tag must have" && exit 3
image_name="ccr.ccs.tencentyun.com/aisec/skg_gremlin:${tag}"

#clean old images 
[ $(docker images ${image_name} | tail -n+2 | wc -l) -gt 0 ] && docker rmi ${image_name}

cd $(pwd)/`dirname $0`
rm -rf apache-tinkerpop-gremlin-server-3.3.2
rm -rf skglib
cp ../gremlin-server/target/apache-tinkerpop-gremlin-server-3.3.2-standalone apache-tinkerpop-gremlin-server-3.3.2 -rf
cp -rf /data/skglib .
docker build -t ${image_name}  --network=host .
echo "build ok"
docker images ${image_name}

#push image
[ ${is_push:-false} == true ] && {
    docker login  --username=100005595966 -p skgimage123 ccr.ccs.tencentyun.com
    docker push ${image_name}
    echo "Success push"
}
