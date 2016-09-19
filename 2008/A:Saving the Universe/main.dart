import 'dart:async';
import 'dart:io';
import 'dart:convert';

main() async{
  String content = await readFile("input.txt");
  List<String> lineList = parseByLine(content);
  parse(lineList);
  //print(lineList);
}


Future readFile(String fileName) async{
  File file = new File("input.txt");
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

void parse(List<String> file){

  int cases = int.parse(file[0]);
  print(file[1]);
  int index = 1;
  List<List<String>> allEngines = new List<List<String>>();
  List<List<String>> allQueries = new List<List<String>>();

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

    allEngines.add(engines);
    allQueries.add(queries);

  }


}
