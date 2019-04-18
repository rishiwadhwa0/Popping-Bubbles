-I downloaded the ofxJSON add-on (link is in my proposal) and simply put it int he addons folder in my openframeworks directory.

-I have experimented with the examples included in the ofxJSON addon for reading and writing files. So far, I have successfully been able to use it to parse some sample json files they gave using string streams. The program then draws the data from the stringstream to an openframeworks window.

-As for the clicking portion of my game, I experiemented with clicking circles and changing the color each time the circle is pressed within its area using the ofx draw functions. I imagine creating circle objects for my game with radius and time-to-draw fields and using these object properties to draw them properly.

-Figured out how to make the game full-screen. I figure this is a good thing to do since some people might have small laptops. A gam shold be a fll-immersive experience!

-Seems like for drawBitString() there's no way to change the font. I will have to work with small text size for testing. 

-Have decided to keep the parsing in the setup since I only need to do this once. However, to draw the bubbles I will use the draw or update methods.

-For organizing my data, I have decided to go for a vector that stores a bunch of bubbles.