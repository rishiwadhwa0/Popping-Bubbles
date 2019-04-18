What I'd like to do:

-Essentially, I want my game to read in a JSON file, using the ofxJSON library, that contains information about several circles to draw (i.e. the size of a circle and the time to draw it) so that the screen a circle is drawn on the screen corressponding to the times associated with each circle object in the JSON file. 

-While the game is running, what my user will have to do is click on as many circles as fast as possible so that a certain amount of circles (let's say 6 for now) are not all on the screen at the same time (don't let them pile up!). This is somewhat analagous to something like the famous Fruit Ninja game where you cannot let three fruits be uncut.

-If the user survives the whole time span that the JSON file specifies without ever having 6 circles (or whatever number I eventually decide) ever be on the screen at the same time, he or she wins the game. Otherwise, the user will experience a loss, probably receiving a score of how many circles he or she popped (or some other measurment of score if I find something better).

-The reason I want to do this game is because I love games like Fruit Ninja and Dance Dance Revolution in which you have to be focused and react quickly, and this game is somewhat similar to those games. This game also seems like something that I could turn into an IOS app and release on the app store later on. 

-A stretch goals would be to add in some user interface so that the user can select how fast he wants to scale the timings by. Another one would be that the circles could move on the screen.

Background I have:

-I don't have any technical background with creating games of this sort, but I know what a JSON file is from the assignments in CS 126, and I believe that I can use the general problem solving skills that I have learned so far from this class to to implement code for this project. However, I do have some background knowledge in the sense that I used to play a lot of games like Fruit Ninja, Dance Dance Revolution, Traffic Rush (my high score is like 900-something I think), and honestly the only thing that I ever liked about taking eye exams is that I got to play this game that tests my peripheral vision that's kind of like that game that I want to build (except you have to stare at the center of the screen). 

What I think I will need to accomplish the project:

-The main external library I will be using is the ofxJSON library (I downloaded this from: https://github.com/jeffcrouse/ofxJSON). I believe that I will have to make some JSON files myself and have my program draw the circles at the times that the JSON file specifies.

-I will probably need to have a bubble class (i.e. representing a circle with its radius and time-to-draw) of whose object is generated for every time associated with each circle in the JSON file.

-I will probably use my linked list or the standard library linked list to keep track of how many bubbles there are on the screen. If a new time is parsed from the JSON, a new bubble associated with that time will appear at a random position on the screen and will be added to the list. If a bubble is popped, that object will be removed from the screen (probably painted over) and removed from the list. If the list's size is more than 5, the user loses. 
