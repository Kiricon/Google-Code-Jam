const fs = require('fs');

var readSource = 'B-large.in';
var outputData = "";
/** Using the readFile API - Asynchronous */
fs.readFile(readSource, "utf8", function(err, data){
  if ( err ){ throw err;}
  var temp = data.split('\n');
  for(var i = 1; i <= temp[0]; i++){
    flipTheFlap(convert(temp[i]), i);
  }
  /** write file syncronously **/
fs.writeFileSync('output.txt', outputData, {"encoding":'utf8'});
//  flipTheFlap(convert(temp[5]));
});

function convert(input){
  var temp = input.split('');
  temp.forEach(function(value, index){
    if(value == "+"){
      temp[index]= true;
    }else if(value == "-"){
      temp[index] = false;
    }
  });
  return temp;
}

function flipTheFlap(arr, index){
  var loops = 0;
  while(arr.every(isTrue) == false){
  var i = flopIndex(arr);
  if(i != "done"){
    //console.log(arr+":"+i);
    arr = flipo2(arr, i);
    loops++;
  }
  }
  outputData += "Case #"+index+": "+loops+"\n";
}


function flopIndex(arr){
//  var flapdex = 'hotdog';
//console.log(arr);
  var flapdex = 'done';
  arr.forEach(function(value, index){
    if(value != arr[index+1] && arr[index+1] != undefined && flapdex == 'done'){
      //console.log(value+":"+arr[index+1]);
    //  console.log('this');
      flapdex = index;
    }else if (arr.every(isFalse)){
      flapdex = arr.length -1;
    //  console.log('that');
    }
  });
  return flapdex;
}

function flipo2(arr, index){
  var newarr = arr;
  for(var i = 0; i <= index; i++){
    newarr[i] = !newarr[i];
  }
  return newarr;
}

function isFalse(element, index, array) {
  return element == false;
}

function isTrue(element, index, array) {
  return element == true;
}
