const fs = require('fs');

var readSource = 'A-large.in';
var outputData = "";
/** Using the readFile API - Asynchronous */
fs.readFile(readSource, "utf8", function(err, data){
  if ( err ){ throw err;}
//  console.log("Reading file asynchronously");
    main(parseFile(data));
});

function runOptions(string){
  string = string.split('');
  //console.log(string.length);
  var words =[];
  var combos = combinations(string.length-1);
  //console.log(combos.length);
  combos.forEach(function(set){
    var word = string[0];
    set.forEach(function(value, index){

      if(value){
        word = string[index+1]+word;
      }else{
        word = word+string[index+1];
      }
    });
    words.push(word);

  });

  words = words.sort();
  return words;
}

function runOptions2(string){
  string = string.split('');
  //console.log(string.length);
  var word = string[0];
  for(var i =1; i < string.length; i++){
    var temp = word.split('');
    if(string[i]>temp[0]){
      word = string[i]+word;
    }else{
      word = word+string[i];
    }
  }

  return word;
}

function combinations(n) {
  var r = [];
  var z = 0;
  //n = n -2;
  for(var i = 0; i < (1 << n); i++) {
    var c = [];
    for(var j = 0; j < n; j++) {
      c.push(i & (1 << j) ? true : false);
    }

    r.push(c);
  }
  return r;
}

function parseFile(input){
  input = input.split('\n');
  var arr = [];
  for(var i=1; i < (input.length -1); i++){
    arr.push(input[i]);
  }
  return arr;
}

function main(arr){
  arr.forEach(function(value, index){
    var temp = runOptions2(value);
    outputData += "Case #"+(index+1)+": "+temp+"\n";
  });
  fs.writeFileSync('output.txt', outputData, {"encoding":'utf8'});
}


/*
var final = runOptions("cab");
console.log(final[final.length-1]);
*/

//console.log(combinations(4));
/** write file syncronously **/
//fs.writeFileSync('output.txt', outputData, {"encoding":'utf8'});
