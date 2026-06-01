
import { generate } from "./generation.js"
import { join } from "node:path";
import process from "node:process"
import fs from 'fs';
import {constants} from "node:buffer"

function get_name(range_start, range_end, ratio)
{
  let prefix;
  let name;

  if(ratio < 0.2)
    prefix = "simple_"
  else if(ratio >= 0.2 && ratio < 0.5)
    prefix = "medium_"
  else if(ratio >= 0.5 && ratio < 1)
    prefix = prefix = "comlex_"
  name = prefix + range_start + "_" + range_end + "_" + ratio 
  return (name)
}

function check_file_exist(path)
{
  try {

    fs.accessSync(path, fs.constants.R_OK)
    console.log("The file exist we will delete the old one and create a new one")
    fs.unlink(path, err =>{
      if(err)
        console.log("Error delete file")
    })
  } catch (error) {
      console.log("The file doesnt exist we will create one")
  }
}

function multi_generation(r_start, r_end, mn_value, mx_value, rtio)
{
  let range_start = parseInt(r_start);
  const range_end = parseInt(r_end);
  const min_value = parseInt(mn_value);
  const max_value = parseInt(mx_value);
  const ratio = parseFloat(rtio);

  const name = get_name(range_start.toString(), range_end.toString(), ratio);
  const path = "generateur/listes/" + name
  if(name == undefined)
  {
    console.log("Error creation name!!!");
    return (-1);
  }
  check_file_exist(path)
  console.log(range_start)
  while(range_start <= range_end)
  {
    let list = generate(min_value, max_value, range_start, ratio).concat("\n");
    fs.writeFileSync("generateur/listes/" + name, list, {flag: 'a'} ,err => {
      if(err)
      {
        console.log(err)
        return(-1)
      }
    })
    range_start++;
  }
  return (1)
}

function main(argv)
{
  let r;
  const ratio = parseFloat(process.argv[6]);

  if(ratio < 0 || ratio > 1)
  {
    console.log("bad ratio!!!");
    return (false);
  }
  r = multi_generation(process.argv[2].toString(), process.argv[3].toString(), process.argv[4].toString(), process.argv[5].toString(), process.argv[6])
  if(r == -1)
    console.log("Erreur creation des liste de valeur")

}

main()