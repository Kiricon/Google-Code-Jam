import 'dart:async';
import 'dart:io';
import 'dart:convert';
import 'dart:math';

main() async{
  String content = await readFile("A-small-practice.in");
  List<String> lineList = parseByLine(content);
  var cases = parse(lineList);

  writeFile("Output.txt",solve(cases));



}

String solve(cases){

  int index = 1;
  String output =""; 
  for(var testCase in cases){
    List<String> engines = testCase[0];
    List<String> queries = testCase[1];

    List<int> hits = new List<int>();

    for(String engine in engines){
      int hit = 0;
      for(String query in queries){
        if(engine == query){
          hit++;
        }
      }
      hits.add(hit);
    }

    output += 'Case #${index.toString()}: ${hits.reduce(min).toString()}\n';
    index++;
  }

  return output;
}

Future readFile(String fileName) async{
  File file = new File(fileName);
  return await(file.readAsString(encoding: ASCII));
}


List<String> parseByLine(String line){
  return line.trim().split('\n');
}


void writeFile(String name, String content){
  var writeFile = new File(name).openWrite();
  writeFile.write(content);
  writeFile.close();
}


parse(List<String> file){

  int cases = int.parse(file[0]);
  print(file[1]);
  int index = 1;
  var Cases = [];


  for(int x = 1; x <= cases; x++){
    List<String> engines = new List<String>();
    List<String> queries = new List<String>();
    int curr;

    curr = index;
    for(int i = curr+1; i <= curr+int.parse(file[curr]); i++){
      //print(i);
      engines.add(file[i]);
      index = i;
     // print(index);
    }
    index += 1;
    curr = index;
    for(int i = curr+1; i <= curr+int.parse(file[curr]); i++){
      queries.add(file[i]);
      index = i;
    } 
    index+=1;

    Cases.add([engines, queries]);

  }

  return Cases;

}
