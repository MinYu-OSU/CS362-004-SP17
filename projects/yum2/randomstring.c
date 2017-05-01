//
// Min Yu
// Random Test Quiz

/*

First I looked over the condition which the program to spit out "error" message, and by working
backward from the testme(), I was able to 'guess' a solution for the random testing.
In inputChar(), I made a string of characters that are need to trigger all of if in testme().
Crated a random number between 0 and length 9 (  [({ ax})] ) and returned the string at index.
Moving on to inputString(), I made a string with characters that are needed to trigger all true of
the AND statements in the last if condition in testme(). I was unsure if I needed to test all of the
'A-Z, a-z' in ASCII but decided to test with only {R,E,S,T } for the sake of being simple. It 
runs through 0 to length of 5 (since we want the word 'reset') and return the character of strings
once the array is full. Once this was coded, testme() simply runs the code until correct order or set
of inputChar() and inputString() was generated. 
*/