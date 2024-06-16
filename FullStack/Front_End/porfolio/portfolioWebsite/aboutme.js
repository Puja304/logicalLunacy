const move = document.getElementsByTagName("img");

// Convert HTMLCollection to an array
Array.from(move).forEach(element => {
    element.addEventListener("click", function () {
        element.classList.add("whenClicked");
        
        document.body.onpointermove = event => {
            const { clientX, clientY } = event;
        
            setTimeout(() => {
                element.animate({
                    left: `${clientX}px`,
                    top: `${clientY}px`
                }, {duration: 1000, fill: "forwards"});
            }, 0); // Delay of 700 milliseconds (adjust as needed)
        }
    });
});

