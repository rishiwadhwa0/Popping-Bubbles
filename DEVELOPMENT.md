-I downloaded the ofxJSON add-on (link is in my proposal) and simply put it int he addons folder in my openframeworks directory.

-I have experimented with the examples included in the ofxJSON addon for reading and writing files. So far, I have successfully been able to use it to parse some sample json files they gave using string streams. The program then draws the data from the stringstream to an openframeworks window.

-As for the clicking portion of my game, I experiemented with clicking circles and changing the color each time the circle is pressed within its area using the ofx draw functions. I imagine creating circle objects for my game with radius and time-to-draw fields and using these object properties to draw them properly.

-Figured out how to make the game full-screen. I figure this is a good thing to do since some people might have small laptops. A gam shold be a fll-immersive experience!

-Seems like for drawBitString() there's no way to change the font. I will have to work with small text size for testing. 

-Have decided to keep the parsing in the setup since I only need to do this once. However, to draw the bubbles I will use the draw or update methods.

-For organizing my data, I have decided to go for a vector that stores a bunch of bubbles.

-I think in terms of best design practice, I will overload the comparison operator to be able to sort my list using the best sorting algorithms that come with the standard library. 

-Not exactly sure why Visual Studio is not building properly. I cut and pasted classes into the source directory, and now it's not working.
Update: Implemented work-around by using ../Bubble.h for the include statement
Update: Apparently Visual Studio doesn't autodetect that you have changed directories. You must remove the file from the project and re-add it. It works now.

-Due to the my need from removing the first elements of the bubbles list, I will be switching from using a vector to a deque (never used this before, but I'll give it a shot!).

-Circles are being drawn, but don't stay on the screen!
Update: Discovered ofSetBackground(false) but still didn't work.
Update: I believe I have discovered a real bug with OpenFrameworks. The setBackroundAuto shows a darkened screen with everything blacked out if you're displaying a fullscreen window. I have fixed this problem by displaying a 1000x1000 window.
Update: My code moderator has told me I can use OF_GAME_MODE, but is still glitchy. However, I can still re-size the window to fllscreen and the game works perfectly fine.

-I couldn't find anything available to dynamically center font. Personally, I like the text in the top left anyways. 

-I found it useful to put the if-conditionals to check if the game has or has not started/ended and return, so that the rest of the code is not indented. 
Ex: 
if (bad) {
	return;
}
//rest of code

instead of:

if (not bad) {
	//rest of code
}

-My friend who actually does game dev. told me to consider adding sond to my game, since that avoids awkward sildence. I think I will put sounds when a bubble comes up on the screen and when you pop the bubbles. 