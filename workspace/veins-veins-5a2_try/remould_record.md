# Remould records

Try to modity VEINS files to learn it and build my project.

## Replace SUMO files. 

I replaced sumo related files. 
```
        <net-file value="b4atom.net.xml"/>
        <route-files value="dua.rou.xml"/>
        <additional-files value="dayuan.atom.add.xml"/>

        Changed erlangen.launchd.xml
```

Failed. See [files](./examples/veins_sumofail/)

## Just change vehicles routes.

Generate a new route file using original erlangen Uinv's net file. Then we changed "erlangen.sumo.cfg" to use the new route file.
```linux
$/usr/local/opt/sumo/share/sumo/tools/randomTrips.py -n erlangen.net.xml -o dayuan.erlangen.trips.xml  --route-file dayuan.erlangen.rou.xml -p 3 --begin 0 --end 1000
calling  /usr/local/opt/sumo/share/sumo/bin/duarouter -n erlangen.net.xml -r dayuan.erlangen.trips.xml --ignore-errors --begin 0 --end 3600 --no-step-log --no-warnings -o dayuan.erlangen.rou.xml
Success.

$ll
-rw-r--r--  1 dyt  staff   109K Oct 10 16:29 dayuan.erlangen.rou.alt.xml
-rw-r--r--  1 dyt  staff    73K Oct 10 16:29 dayuan.erlangen.rou.xml
-rw-r--r--  1 dyt  staff    23K Oct 10 16:29 dayuan.erlangen.trips.xml
```

- ***../../../../tools/randomTrips.py***: Find the correct path of randomTrips.py file.
- ***-n dayuan.cross.net.xml***: As input file. Usually it's a network file.
- ***-o dayuan.trips.trips.xml***: As output file. `randomTrips.py` generates a trip file. Not route file by default.
- ***--route-file dayuan.cross.rou.xml***: Add "--route-file" attribute it will call DUAROUTER automatically backend and generate route file for us. 
- ***-p 1***: The arrival rate is controlled by option --period/-p <FLOAT> (default 1). By default this generates vehicles with a constant period and arrival rate of (1/period) per second. By using values below 1, multiple arrivals per second can be achieved.

Tried `sumo-gui -c erlangen.sumo.cfg` it works well.