const disp = document.getElementById("result");

function game(choice){
    const choices=["rock","paper","scissors"];
    const ComputerChoice= choices[Math.floor(Math.random()*3)];
    let display = "Your Choice : " + choice + "<br>Computer's Choice : " + ComputerChoice + "<br>";
    if(choice === ComputerChoice){
       display += "Its a tie!"

    }
    else if(
        (choice === "rock" && ComputerChoice === "scissors") ||
        (choice === "paper" && ComputerChoice === "rock") ||
        (choice === "scissors" && ComputerChoice === "paper")
    ){
        display += "You WON!";
    } else {
        display += "You LOST!";
    }
    disp.innerHTML = display;
}
