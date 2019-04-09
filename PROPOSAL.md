What I'd like to do:

-Essentially, I want my game to recognize certain distinct beats of a pre-loaded song so that the screen is populated with a circle each time a distinct beat is processed by my program. 

-What my user will have to do is click on as many circles as fast as possible so that a certain amont of circles (let's say 6 for now) are not on the screen all at the same time. This is somewhat analagous to something like the famous Fruit Ninja game where you cannot let three fruits not be cut.

-If the user survives the whole song without ever having 6 circles (or whatever number I eventually decide) ever be on the screen at the same time, he or she wins the game. Otherwise, the user will experience a loss, probably receiving a score of how many circles he or she popped, for example (or some other measrment of score if I find something better).


What I think I will need to accomplish the project:

-One of the libraries I will be using is the openframeworks sound library (provided in the zip file of openframeworks). I believe that extracting the right type of beat at the right time is somewhat complicated and will require a good amount of time understanding how to deal with the sound library and what the different properties of sound means themselves. 

-I will probably need to have a bubble class (i.e. representing a circle with its x and y coordinates that are randomly picked) that is generated each time a distinct beat is processed.

-I will probably use my linked list or the standard library linked list to keep track of how many bubbles there are on the screen. If a bubble is popped, that object will be removed from the screen (either painted over or actually removed depending on how I decide to draw the shape) and from the list. If a new distinct beat is processed, a new bubble will appear at a random position on the screen and will be added to the list.
