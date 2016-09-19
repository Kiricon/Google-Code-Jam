import 'dart:async';
import 'dart:io';
import 'dart:convert';

void main() async{
  String content = await readFile("input.txt");
  List<String> lineList = parseByLine(content);
  print(lineList);
  writeFile("test.txt", "hello \nworld");
}


Future readFile(String fileName) async{
  File file = new File("input.txt");
  return await(file.readAsString(encoding: ASCII));
}

List<string> parseByLine(String line){
  return line.trim().split('\n');
}

void writeFile(String name, String content){
  var writeFile = new File(name).openWrite();
  writeFile.write(content);
  writeFile.close();
}
