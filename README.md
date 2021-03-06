# Treemo

Treemo is a playful, small and self-contained solution that aims to make monitoring the health of your plants easier and more fun.

## How It Works

Treemo sits with your plants and frequently takes measurements of the moisture in the soil. It's face shows how the plant is doing. e.g. happy when there is a good amount of moisture and sad when your plant needs a drink.


## Hardware

Treemo is made up of a few small components that are pretty commonly found and very easy to assemble and work with.

To build your own Treemo you will need:

* NodeMCU (code will also work with Arduino boards but you'll need to make some modifications to code and the casing to fit, or design your own!)
* Soil Moisture Sensor (We used a YL-69 but have tested with Funduino sensors too)
* LED matrix with MAX7219 controller
* Jumper Cables
* Some time to spare


## Calibration

To ensure your Treemo is providing accurate info, it's best to calibrate it depending on the plant(s) it will be used with. Many plants require different amounts of moisture to thrive so it's important to make sure you're getting correct and useful information.

To calibrate your Treemo, you'll need to connect the Arduino to your computer and open up Arduino IDE. Open the Serial monitor and you should see live readings from the moisture sensor every second.

Get three different plants/soil samples. One with a good amount of water, one that is OK and one that needs to be watered. Test Treemo in the different samples and take note of the results from Serial Monitor.

You'll need to adjust the values in the TreemoOS Arduino sketch to suit your own situation. There are three if statments that control this. 

They'll look like this:

* `if (moisture >= 1000)` - Sad
* `if (moisture >= 500 && moisture <= 700)` - Happy
* `if (moisture <= 200)` - Very Happy

Change the values to the values you got from your readings. If you break something, you can always download everything from this repo and start fresh.

# Contributing

We'd love to see what you have to add! We happily accept contributions, especially through pull requests on GitHub.

Please read CONTRIBUTING.md for important guidelines to follow.

