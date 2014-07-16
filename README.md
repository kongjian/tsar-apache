####tsar采集apache的插件安装步骤

1.首先编译asar_apache_agent    
  `make`

2.将asar_apache_agent部署到服务器   
  拷贝到指定目录，比如/usr/local/sbin/asar_apache_agent   

3.配置apache的CustomLog，注意asar_apache_agent的目录要保持一致   
  `CustomLog "|/usr/local/sbin/asar_apache_agent" "%D"`    
  
4.重启apache，配置/etc/tsar/tsar.conf确保开启mod_apache on
  
    -bash-3.2$/etc/init.d/httpd start
    Starting httpd:                                            [  OK  ]
    -bash-3.2$ ps aux|grep agent
    root     12323  0.0  0.0   3652   348 ?        S    14:22   0:00 /usr/local/sbin/asar_apache_agent
    kongjian 12367  0.0  0.0  61132   752 pts/14   S+   14:22   0:00 grep agent
    
5.使用tsar查看apache的数据

    tsar --apache -l -i 1
    -bash-3.2$ tsar --apache -l -i 1
    Time              ------------------apache----------------
    Time                 qps      rt    sent    busy    idle
    16/07/14-14:25:41   8.1K    0.09  794.00    9.00   30.00
    16/07/14-14:25:42   7.8K    0.09  766.00   10.00   30.00
    16/07/14-14:25:43   8.7K    0.09  851.00   11.00   29.00
    16/07/14-14:25:44   8.1K    0.09  791.00    9.00   31.00

6.另外要确保apache能够访问server-status?auto页面

    -bash-3.2$ curl localhost/server-status?auto
    Total Accesses: 89588
    Total kBytes: 8592
    CPULoad: .879688
    Uptime: 640
    ReqPerSec: 139.981
    BytesPerSec: 13747.2
    BytesPerReq: 98.2074
    BusyWorkers: 1
    IdleWorkers: 32
    Scoreboard: __._____.________._._W__.________._...____......................................................................................................................................................................................................................

done

