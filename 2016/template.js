const fs = require('fs');

var readSource = 'input.txt';
var outputData = "yooo doggg";
/** Using the readFile API - Asynchronous */
fs.readFile(readSource, "utf8", function(err, data){
  if ( err ){ throw err;}
  console.log("Reading file asynchronously");
  console.log(data);
});
/** write file syncronously **/
fs.writeFileSync('output.txt', outputData, {"encoding":'utf8'});
