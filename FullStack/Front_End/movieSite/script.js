const APILINK = 'https://api.themoviedb.org/3/discover/movie?sort_by=popularity.desc&api_key=e7be4ba2d84f9cd931b2e97cb81d792c&page=1';
const IMG_PATH = "https://image.tmdb.org/t/p/w1280";
const SEARCHAPI = "https://api.themoviedb.org/3/search/movie?&api_key=e7be4ba2d84f9cd931b2e97cb81d792c&query=";

const main = document.getElementById("section");
const form = document.getElementById("form");
const search = document.getElementById("query");

returnMovies(APILINK)

//takes in what is returned from the API and generates movie listings

function returnMovies(url) {
    fetch(url)
        .then(res => {
            if (!res.ok) {
                throw new Error('Network response was not ok ' + res.statusText);
            }
            return res.json();
        })
        .then(function(data) {
            if (!data.results || !Array.isArray(data.results)) {
                throw new Error('Data format error: results not found or not an array');
            }
            console.log(data.results);
            data.results.forEach(element => {
                const div_card = document.createElement('div');
                div_card.setAttribute('class', 'card');

                const div_row = document.createElement('div');
                div_row.setAttribute('class', 'row');

                const div_column = document.createElement('div');
                div_column.setAttribute('class', 'column');

                const image = document.createElement('img');
                image.setAttribute('class', 'thumbnail');
                image.setAttribute('id', 'image');

                const title = document.createElement('h3');
                title.setAttribute('id', 'title');

                title.innerHTML = `${element.title}`;
                image.src = IMG_PATH + element.poster_path;

                div_card.appendChild(image);
                div_card.appendChild(title);
                div_column.appendChild(div_card);
                div_row.appendChild(div_column);

                main.appendChild(div_row);
            });
        })
        .catch(error => {
            console.error('Error fetching and parsing data', error);
        });
}

  
  form.addEventListener("submit", (e) => {
    e.preventDefault();
    main.innerHTML = '';
  
    const searchItem = search.value;
  
    if (searchItem) {
      returnMovies(SEARCHAPI + searchItem);
        search.value = "";
    }
  });


