const fs = require('fs');

var readSource = 'C-large.in';
var outputData = "Case #1:\n";
/** Using the readFile API - Asynchronous */
fs.readFile(readSource, "utf8", function(err, data){
  if ( err ){ throw err;}
  //console.log("Reading file asynchronously");
  data = data.split('\n');
  data = data[1].split(' ');
  combinations(data[0], data[1]);
  fs.writeFileSync('output.txt', outputData, {"encoding":'utf8'});
});

function convertBase(string, base){
  total = 0;
  arr = string.split('')
  arr.reverse();
  arr.forEach(function(value, index){
    if(value == '1'){
      //console.log('dog');
      total += Math.pow(base, index);
      console.log(typeof total);
    }
  });
  return total;
}

function isPrime3(n) {
 if (isNaN(n) || !isFinite(n) || n%1 || n<2) return false;
 if (n%2==0) return (2);
 if (n%3==0) return (3);
 var m=Math.sqrt(n);
 for (var i=5;i<=m;i+=6) {
  if (n%i==0)     return i;
  if (n%(i+2)==0) return (i+2);
 }
 return false;
}


function checkJamCoin(coin){
  //coin = coin.toString();
  //console.log(coin);
  var divisList = '';
  for(var i = 2; i < 11; i++){
    //console.log(convertBase(coin, i));
    var divis = isPrime3(convertBase(coin, i));
    if(divis){
      divisList += divis+' ';
    }else return false;
  }
  return coin+" "+divisList;
}


function combinations(n, limit) {
  var r = [];
  var z = 0;
  n = n -2;
  for(var i = 0; i < (1 << n) && z < limit; i++) {
    var c = [];
    for(var j = 0; j < n; j++) {
      c.push(i & (1 << j) ? '1' : '0');
    }

    var test = "1"+c.join('')+"1";
    var check = checkJamCoin(test);
    if(check){
      //console.log(test);
      outputData += check+"\n";
      z++;
    }
  }
  return r;
}
