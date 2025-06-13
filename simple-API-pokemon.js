
//Js logic using simple get request to fetch the api from server(using async await)
async function getPokemon(){
    try{
        const name=document.getElementById("pokemon").value.toLowerCase();
        const response = await fetch(`https://pokeapi.co/api/v2/pokemon/${name}`);  //fetches the pokemon name given by user
        if(!response.ok){
            throw new Error("Failed to fetch the resource");
        }
        const resource = await response.json(); //async resource is the whole data fetched by the api
        const pokiImage = resource.sprites.front_default;    //this is the image url with in the resource accesed using the predefined properties of the resource
        const imageElement= document.getElementById("pokemonImage");
        imageElement.src = pokiImage; 
        imageElement.style.display = "block";


    }
    catch(error){
        console.log(error);

    }
    
}