const fs = require('fs');

var readSource = 'A-small-attempt2.in';
var outputData = "";

/** Using the readFile API - Asynchronous */
fs.readFile(readSource, "utf8", function(err, data){
  if ( err ){ throw err;}
    var temp = data.split('\n');
    for(var z = 1; z <= temp[0]; z++){
      doTheCheck(temp[z], z);
    }
    fs.writeFileSync('output.txt', outputData, {"encoding":'utf8'});
    //console.log(temp);
});

function doTheCheck(input, index){
  var keepTrack = ['zz', '', '', '', '', '', '', '', '', ''];
  var i = 1;
  var lastNum = 0;
  while(gotTheGoods(keepTrack) == false){
    var temp = i * input;
    if(temp != input || i == 1){
    if(temp > 9){
    temp = (""+temp).split('');
  }else temp = [temp];
  //console.log(temp);
    temp.forEach(function(value){
      value = parseInt(value);
      //console.log(value);
      if(!isInArray(value, keepTrack)){
        lastNum = "Case #"+index+": "+(i * input);
        keepTrack[value] = value;

      }else{
        //console.log(value);
      }
    });
  }else{
    keepTrack = [0,1,2,3,4,5,6,7,8,9];
    lastNum = "Case #"+index+": INSOMNIA";
  }
  //  console.log(i*input);
    i++;
  }
  outputData += lastNum+"\n";
}

function gotTheGoods(array){
  for(var i = 0; i <= 9; i++){
    if(i != array[i]){
      return false;
    }
  }
  return true;
}

function isInArray(value, array) {
  return array.indexOf(value) > -1;
}

//doTheCheck(1);
/** write file syncronously **/
//fs.writeFileSync('output.txt', outputData, {"encoding":'utf8'});
