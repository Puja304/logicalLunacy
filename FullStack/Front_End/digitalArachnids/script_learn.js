const user = {
    name: "Puja",
    age: 21,
    married: false,
    purchases : ['laptop','tablet', 'phone', 'blowdry'],
 
    sayName : function (){
        console.log(this.name);
    }

}


user.sayName();

let aList = ['Puja','Minal','Birju','Sawan','Bhavya','Shivani','Shweta', 'Akash'];

for (var person of aList){  // this prints out the value of each element
    console.log(person);
}

for (var person in aList)[  // this prints out each indice
    console.log(person)   //for some reason cannot use semi colon at the end or it throws an error
] 

if(aList.includes('Ramesh')){
    console.log("Found Ramesh");
} else{
    console.log("Did not find Ramesh");
}

if(aList.includes('Minal')){
    console.log("Found Minal! She is at index %i", aList.indexOf('Minal'));
}


// you can create a function and then that tests an element. if you want the index of the first element in the array that actually passes the test
//use findIndex

secondList = [5,8,13,14,3,9,6];
function isBig(num){
    return (num > 10);
}

console.log(secondList.findIndex(isBig));





