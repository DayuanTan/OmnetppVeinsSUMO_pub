# OmnetppVeinsSUMO_pub

Install [SUMO](https://github.com/DayuanTan/SUMO_dy_public), OmNet++ and Veins respectively.(Or [Instan Veins](https://veins.car2x.org/documentation/instant-veins/))

`SUMO is easy to install. You can follow the official github page. OmNet++ is not install-friendly. I used v5.5.1 and tried on Window, Mac, Ubuntu, even docker but I encountered different kinds of errors. Finally I installed it on Ubuntu 16.04, and it works well later, which is the ONLY platform I suggest for OmNet++ v5.5.1. Instan Veins is also recommended if you only want Veins. But I didn't use it.`

Then leant some basic knowledge about [SUMO (learn here)](https://github.com/DayuanTan/SUMO_dy_public) and [OmNet++ (learn here)](https://docs.omnetpp.org/tutorials/tictoc/) before you start Veins. 

## Install Veins:

I don't think the official install instruction is good, readable. It's kind of confusing. I suggest to do it as follows:

1. Install SUMO, following instructions on [official website](https://sumo.dlr.de/userdoc/Installing.html).

I recommend to use Ubuntu 16.04. So what you need to do is just:
```
sudo add-apt-repository ppa:sumo/stable
sudo apt-get update
sudo apt-get install sumo sumo-tools sumo-doc
```

Then you maybe want to download the latest source code from its [github repositories](https://github.com/eclipse/sumo). Put those code at somewhere you like. If you find you miss some files when you use SUMO in future, you can just copy the missed files into your install directory. 

2. Install OmNet++ 5.5.1. I suggest to follow the official install manual but only install it on Ubuntu 16.04. As I mentioned before, it's the only one I installed successfully.

3. Install Veins. 

Follow the step 3 on [this page](https://veins.car2x.org/tutorial/). Download the source code, import existing project and then build all.

The step 4 and Final step are worth to read them, but you don't need to follow them. 

To run it, 

## Run Veins:

` ./sumo-launchd.py -vv c sumo
`
