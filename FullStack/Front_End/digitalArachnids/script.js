const bigName = document.querySelector(".name1");  //turn the code into an object. so can use other object properties with this too


bigName.style.color = "lightbrown"; // basically the .style gives access to all css features!

// we can add a class to a prexisting one as well
// all classes are styled in css, so that's where we add them

bigName.addEventListener('click', function(){  //if clicked once
    bigName.classList.toggle("trialClass");  // changes color to pink when clicked once, and back to original on a reclick
    })




//creates an array of all the items with an image tag in the html    
const allButtons = document.getElementsByTagName("img");  //selects all the a tags within the element with class .header

for (button of allButtons){  //for each image
    button.addEventListener('click', function (){  //when clicked
        console.log("An image has been clicked");  //print this in the console
    })
}


// using the submitted response and updating it on screen:

//we first need an object for the submit button:
const submitB = document.querySelector(".submitBtn");

//add a class to the input tag you want to extract info from (in html). In this case, it's the name input with class .userName
//once added, create an object for it:

const nameInput = document.querySelector(".userInput");
//say once name has been submitted, we want it to appear below the actual div

//we go to html and add a ul (list) element in there where we will keep adding the new info
//let's create an object for it:
const mainList = document.querySelector(".trial");


// now we create the event of clicking submit:
submitB.addEventListener('click', function(){
    //first we create a li element to add to the list:
    const newName = document.createElement("LI");

    //we then fill in the content, taking the value from the input field:
    const newNameContent = document.createTextNode(nameInput.value)

    //we now add the content of the new list element to the new tag we created:
    newName.appendChild(newNameContent);

    //we now add the new list element to the overall list
    mainList.appendChild(newName);

    //and that's it! everytime we click submit, the value in the input box will become a new list element and get added.

})




