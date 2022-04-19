const binary_search_result = document.getElementById('binary_search');
const binary_search_index = document.getElementById('binary_index');
const search = Math.floor(Math.random()*120)+1;
const binary_search_array = [];

(() => {
  let index=0;
  for (let i=1; i<=100; i++) {
    binary_search_array.push(i);
  }
  binary_search_index.innerHTML = search;
})()

function print_binary_search() {
  binary_search_result.innerHTML = binary_search(binary_search_array,search);
}

function binary_search(array, search){
  var start = 0;
  var end = array.length - 1;

  while (start <= end) {
    var middle = Math.floor((start + end) / 2);
    if (array[middle] == search) return middle;
    if (array[middle] > search) end = middle - 1;
    else start = middle + 1;
  }

  return 'Not found in our array';
}
