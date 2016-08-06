const fs = require('fs');

var readSource = 'input.txt';
var outputData = "yooo doggg";
/** Using the readFile API - Asynchronous */
fs.readFile(readSource, "utf8", function(err, data){
  if ( err ){ throw err;}
  //console.log("Reading file asynchronously");
  main(parseFile(data));
});

function parseFile(string){
  string = string.split('\n');
  string = string[0].split(' ');
  return string;
}

function main(arr){
  //var org = arr;
  var track = arr.slice();
  //console.log(track);
  arr.forEach(function(value, index){
    var count = 0;
    for(var i = 0; i < arr.length; i++){
      //console.log(arr[i]);
        if(arr[i] == index+1){
        //  console.log(arr[i]+":"+value+":"+i);
            count++;
          }
    }
    track[index] = count;
  });
  /*
  var newarr = [];
  var newtrack = [];
  track.forEach(function(value, index){
    if(value != 0){
      newarr.push(arr[index]);
      newtrack.push(value);
    }
  });
  console.log(newarr);
  console.log(newtrack); */
  console.log(track);
  console.log(arr);
}



/** write file syncronously **/
//fs.writeFileSync('output.txt', outputData, {"encoding":'utf8'});
