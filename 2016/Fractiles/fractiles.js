const fs = require('fs');

var readSource = 'input.txt';
var outputData = "yooo doggg";
/** Using the readFile API - Asynchronous */
fs.readFile(readSource, "utf8", function(err, data){
  if ( err ){ throw err;}
  //console.log("Reading file asynchronously");
  //console.log(data);
});

function getFrac(k, c, s, pattern){
  var arr=[];
  var i = 1;
  while(i <= c){
    //console.log(Math.pow(k, i));
    var x = Math.pow(k, i);
    var temp =[];
    //console.log('parent:'+arr[i-1]);
    var incr = 0;
    while(x > 0){
    //  console.log('parent:'+arr[i-1])
      if(i == 1){
      temp.push(pattern[incr]);
    }else{
      var parent = arr[i-2];
      for(var z = 0; z < parent.length; z++){
        //for()
      }

    }
      incr++;
      x--;
    }
    arr.push(temp);
    //console.log("p"+arr[0])
    i++;

  }
  return arr;
}

function getFrac2(k, c, s, pattern){
  var arr=[];
  var i = 1;
  while(i <= c){
    var x = Math.pow(k, i);
    var temp =[];
    if(i == 1){
      arr.push(pattern);
    }else{
      var parent = arr[i-2];

    }

  }
  return arr;
}

function makeTree(){
  var pattern = [0, 1];
  var complexity = 2;
  var depth = 3;
  var tree = [];
  var increment = 1;
  while(increment <= depth){
    //There is where we make each level of the tree
    var x = 0;
    var row = [];
    while(x <= Math.pow(increment-1, complexity)){
      //Create the rows
      var z = 0;
      var content = "";
      var idk = 0;
      while(z < complexity){
        //content += 'be:';
        if(increment == 1){
          content += pattern;
        }else{
          //content += tree[increment -2][idk];
          var parent = tree[increment -2];
          //var parlength = parent.length;
          for(var i =0; i < parent.length; i++){
            for(var w = 0; w < 2; w++){
                if(parent[i][w] == 1){
                  content += [1,1];
                }else if(parent[i][w] == 0){
                  content += pattern;
                }
            }
          }

        //  if()
        }
      //  idk++;
        z++;
      }
      row.push(content);
      x++;
    }
    tree.push(row);

    increment++;
  }
  return tree;
}


function makeSlam(){
  var complexity = 2;
  var depth = 3;
  var pattern = [1, 0];
  var tree = [];
  //Lets make the levels
  for(var a = 1; a <= depth; a++){

    tree.push(level);

  }
  return tree;

}
//console.log(makeTree());
console.log(getFrac2( 2,3,2, [1, 0]));
/** write file syncronously **/
//fs.writeFileSync('output.txt', outputData, {"encoding":'utf8'});
