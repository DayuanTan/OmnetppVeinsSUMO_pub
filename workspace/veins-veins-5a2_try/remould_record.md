# Remould records

Try to modity VEINS files to learn it and build my project.

## Replace SUMO files (failed). 

I replaced sumo related files. 
```
        <net-file value="b4atom.net.xml"/>
        <route-files value="dua.rou.xml"/>
        <additional-files value="dayuan.atom.add.xml"/>

        Changed erlangen.launchd.xml
```

Failed. See [files](./examples/veins_sumofail/)

## Just change vehicles routes.

Generate a new route file using **original erlangen Uinv's net file**. Then we changed **"erlangen.sumo.cfg"** and **"erlangen.launchd.xml"** to use the new route file.
```linux
$/usr/local/opt/sumo/share/sumo/tools/randomTrips.py -n erlangen.net.xml -o dayuan.erlangen.trips.xml  --route-file dayuan.erlangen.rou.xml -p 3 --begin 0 --end 1000 --fringe-factor 0
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
- **--fringe-factor <FLOAT>** increases the probability that trips will start/end at the fringe of the network. If the value 10 is given, edges that have no successor or no predecessor will be 10 times more likely to be chosen as start- or endpoint of a trip. This is useful when modelling through-traffic which starts and ends at the outside of the simulated area.

Tried `sumo-gui -c erlangen.sumo.cfg` it works well.

Then I met an error:
```
A runtime error occurred:

Model error: Tried moving host to (2431.172042, 2520.186738) which is outside the playground -- in module (veins::TraCIScenarioManagerLaunchd) RSUExampleScenario.manager (id=6), at t=169s, event #2630

Launch a debugger with the following command?

nemiver --attach=15907 &
```
Check it carefully I found some nodes went outside of the map so I changed "omnetpp.ini" file to make the playground bigger (from 2500x2500x50 to 2600x2500x50).

<!--<vehicle id="24" depart="72.00">
        <route edges="-8403007 -29900564#1 -8402998#2 -8402998#1 -8402997 32270595 33174302#0 33174302#1 4686970#0 4686970#1 122161381 30350448 8364476 30350450#0 30350450#1 30350450#2 4006702#0 31255203#0 31255203#1 -31255203#1"/>
    </vehicle>-->
    <!--<vehicle id="26" depart="78.00">
        <route edges="25472134 30751813 4047446#0 4047446#1 4400949 31982182#0 31982182#1"/>
    </vehicle>-->
    <!--<vehicle id="39" depart="117.00">
        <route edges="-8402997 32270595 33174302#0 33174302#1 4686970#0 4686970#1 122161381 30350448 30350449 4047309 30751813 4047446#0"/>
    </vehicle>-->
    <!--<vehicle id="58" depart="174.00">
        <route edges="44069041#0 44069041#1 4400949 31982182#0 4047241 4797872 4797871 4006668 23339459"/>
    </vehicle>-->

## Change the net file.

Use Sookyoung's net file **net-file value="b4atom.net.xml"**,
**route-files value="dua.rou.xml"**,
**additional-files value="dayuan.atom.add.xml"**.

Change **"erlangen.sumo.cfg"** and **"erlangen.launchd.xml"** to use the new net, route  and add files.

Tried `sumo-gui -c erlangen.sumo.cfg` it works well.