function print_merge_sort() {
  let temp_array = [];
  for (let i=10; i>0; i--) {
    temp_array.push(i);
  }
  let new_array = merge_sort(temp_array);
  document.getElementById('merge_sort_span').innerHTML = '[' + new_array.join(',') + ']';
}

function merge_sort(array) {
  if (array.length < 2) {
    return array;
  }
  var middle = Math.floor(array.length/2);
  var left = array.slice(0, middle);
  var right = array.slice(middle);
  return merge_sort_sliced(
    merge_sort(left), merge_sort(right)
  );
}

function merge_sort_sliced(left, right) {
  let new_array = [];
  while (left.length && right.length) {
    if (left[0] < right[0]) new_array.push(left.shift());
    else new_array.push(right.shift());
  };

  return new_array.concat(left.slice().concat(right.slice()));
}
