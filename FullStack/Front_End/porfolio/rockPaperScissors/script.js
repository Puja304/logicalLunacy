let letsPlay = document.querySelector(".button_begin");
let options = document.querySelector(".buttons_game");
let name1 = document.querySelector("#name");
let pwins = document.querySelector("#player_wins");
let cwins = document.querySelector("#computer_wins");
let twins = document.querySelector("#tie");
let replay = document.querySelector(".replay");
let replay_options = document.querySelectorAll(".replay button");
let userChoiceImg = document.getElementById("userChoiceImg");
let computerChoiceImg = document.getElementById("computerChoiceImg");
let rematch = document.querySelector(".allAgain");


let updateScore = (player_score, computer_score, tie_score) => {
    document.querySelector(".player h4").textContent = player_score;
    document.querySelector(".computer h4").textContent = computer_score;
    document.querySelector(".ties h4").textContent = tie_score;
}

let player_score = 0;
let computer_score = 0;
let tie_score = 0;
updateScore(player_score, computer_score, tie_score);

let choices = ['Rock', 'Paper', 'Scissors'];

let winning = {
    "Rock": "Scissors",
    "Paper": "Rock",
    "Scissors": "Paper"
};

let determineWinner = (choice1, choice2) => {
    console.log("choice 1 is " + choice1 + " and choice 2 is: " + choice2);
    if (choice1 === choice2) {
        return 1; // Tie
    } else if (winning[choice1] === choice2) {
        return 0; // Player wins
    } else {
        return 2; // Computer wins
    }
}

let randomInteger = (min, max) => {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

const three_buttons = document.querySelectorAll(".buttons_game button");
console.log(three_buttons);
console.log(replay_options);



letsPlay.addEventListener('click', function () {
    letsPlay.classList.add("turn_off");
    options.classList.add("turn_on");

    userChoiceImg.classList.add("wiggle");
    computerChoiceImg.classList.add("wiggle");

    for (let button of three_buttons) {
        button.addEventListener('click', function () {
            userChoiceImg.classList.remove("wiggle");
            computerChoiceImg.classList.remove("wiggle");

            let userChoice = button.textContent;
            let computerChoiceNumber = randomInteger(0, 2);
            let computerChoiceWord = choices[computerChoiceNumber];

            
            let winner = determineWinner(userChoice, computerChoiceWord);

            console.log(`User choice: ${userChoice}`);
            console.log(`Computer choice: ${computerChoiceWord}`);
            console.log(`Winner: ${winner}`)

            name1.style.display = "none";
            
            if (winner === 0) {
                player_score++;
                pwins.style.display = "flex";
            } else if (winner === 1) {
                tie_score++;
                twins.style.display = "flex";
            } else {
                computer_score++;
                cwins.style.display = "flex";
            }




            updateScore(player_score, computer_score, tie_score);

            // Assuming userChoice and computerChoice are strings like "rock", "paper", "scissors"
            userChoiceImg.setAttribute("src", `${userChoice}.png`);
            computerChoiceImg.setAttribute("src", `${computerChoiceWord}.png`);
            



            name1.classList.add("turn_off");

            options.classList.remove("turn_on");
            replay.classList.add("turn_on");


            
        });
    }

    for (let option of replay_options) {
        option.addEventListener('click', function () {
            if (option.textContent === "Rematch") {
                replay.classList.remove("turn_on");
                options.classList.add("turn_on");

                userChoiceImg.classList.add("wiggle");
                computerChoiceImg.classList.add("wiggle");

                name1.style.display = "flex";
                pwins.style.display = "none";
                twins.style.display = "none";
                cwins.style.display = "none";




                
            } else {
                replay.classList.remove("turn_on");
                rematch.classList.add("turn_on");

                name1.style.display = "flex";
                pwins.style.display = "none";
                twins.style.display = "none";
                cwins.style.display = "none";

                rematch.addEventListener('click', function(){
                    rematch.classList.remove("turn_on");
                    letsPlay.classList.add("turn_on");
                    computer_score= 0;
                    player_score = 0;
                    tie_score = 0;
                    updateScore(player_score, computer_score, tie_score);

                })



                // Reset scores and game state here if needed
            }
        });
    }
});
