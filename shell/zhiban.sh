#!/bin/bash
set -ex
list=(测试1 测试2 测试3)

today=`date +'%s'`
days=$(($today / 86400))
index=$(($days % ${#list[*]}))
name=${list[$index]}
now=`date +'%Y%m%d'`

curl 'https://oapi.dingtalk.com/robot/send?access_token=f9fb8f34959895248b359427a35928fbf12e1710f7a94fba9a59ea8200ad48a5' \
   -H 'Content-Type: application/json' \
   -d '{"msgtype": "text", 
        "text": {
             "content": "今日'$now' sentry值班：'$name'"
        }
      }'

