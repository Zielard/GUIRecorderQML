
//js code

var Info = 0;
var Err  = 1;
var Warn = 2;
var Succ = 3;


function create(logType, str)
{
    let logToReturn = ""
    let logcolor = "#000000"
    switch(logType) {
        case Info:
            logcolor = "#000000"
          break;
        case Err:
            logcolor = "#660000"
          break;
        case Warn:
            logcolor = "#b2b200"
          break;
        case Succ:
            logcolor = "#006600"
          break;
      }
      logToReturn = "<p><font color=\""+logcolor+"\">";
      logToReturn += str;
      logToReturn += "</font></p>";
      return logToReturn;
}