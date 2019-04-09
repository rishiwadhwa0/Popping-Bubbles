What I'd like to do:

-Essentially, I want my game to read in a JSON file, using the ofxJSON library, that contains data about circles to draw (i.e. the size of a circle and the time to draw it) so that the screen is populated with a circle for each time a circle JSON element specifies. 

-What my user will have to do is click on as many circles as fast as possible so that a certain amount of circles (let's say 6 for now) are not all on the screen at the same time. This is somewhat analagous to something like the famous Fruit Ninja game where you cannot let three fruits not be cut.

-If the user survives the whole time span that the JSON file specifies without ever having 6 circles (or whatever number I eventually decide) ever be on the screen at the same time, he or she wins the game. Otherwise, the user will experience a loss, probably receiving a score of how many circles he or she popped, for example (or some other measurment of score if I find something better).

-The reason I want to do this game is because I love games like Fruit Ninja and Dance Dance Revolution ("don't let 'em pile up" games), and this seems like something that I could turn into an IOS app and release on the app store!

What I think I will need to accomplish the project:

-One of the libraries I will be using is the ofxJSON library (I downloaded this from: https://github.com/jeffcrouse/ofxJSON). I believe that I will have to make some JSON files myself and draw the circles at the times that the JSON file specifies.

-I will probably need to have a bubble class (i.e. representing a circle with its x and y coordinates that are randomly picked) of whose object is generated for every time stamp specified for each circle in the JSON file.

-I will probably use my linked list or the standard library linked list to keep track of how many bubbles there are on the screen. If a new time marker is parsed from the JSON, a new bubble associated with that time marker will appear at a random position on the screen and will be added to the list. If a bubble is popped, that object will be removed from the screen (probably painted over) and from the list. 
