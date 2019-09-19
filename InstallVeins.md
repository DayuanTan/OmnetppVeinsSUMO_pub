## Install Veins:

I don't think the official install instruction is good, readable. It's kind of confusing. I suggest to do it as follows:

## 1. Install SUMO.

Following instructions on [official website](https://sumo.dlr.de/userdoc/Installing.html).

I recommend to use Ubuntu 16.04. So what you need to do is just:
```
sudo add-apt-repository ppa:sumo/stable
sudo apt-get update
sudo apt-get install sumo sumo-tools sumo-doc
```

Then you maybe want to download the latest source code from its [github repositories](https://github.com/eclipse/sumo). Put those code at somewhere you like. If you find you miss some files when you use SUMO in future, you can just copy the missed files into your install directory. 

## 2. Install OmNet++ 5.5.1. 

I suggest to follow the official install manual but only install it on Ubuntu 16.04. As I mentioned before, it's the only one I installed successfully.

## 3. Install Veins. 

Follow the step 3 on [this page](https://veins.car2x.org/tutorial/). Download the source code (you're suggested to put it in your OmNet++ workspace directory), import existing project and then build all.

The step 4 and Final step are worth to read them, but you don't need to follow them. 

## To run it

1. In your terminal, go to the path of veins code (suggestion is under OmNet++ workspace directory), find the file `veins-***/sumo-launchd.py`, then run
```
sumo-launchd.py -vv -c sumo
```
