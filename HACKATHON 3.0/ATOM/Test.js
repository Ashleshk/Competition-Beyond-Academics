tot =10;

function getCheckedValue( Buttonname ){
var radios = document.getElementsByName( Buttonname ); // Get radio group by-name
for(var y=0; y<radios.length; y++)
  if(radios[y].checked) return radios[y].value; // return the checked value
}

function getScore(){
var score = 0;
for (var i=0; i<tot; i++)
{  if(getCheckedValue("question"+i)==="-10") score += -10;
if(getCheckedValue("question"+i)==="-5") score += -5; // increment only
if(getCheckedValue("question"+i)==="0") score=score+0;
if(getCheckedValue("question"+i)==="5") score += 5;
if(getCheckedValue("question"+i)==="10") score += 10;}
return score;
}

function returnScore(){
  var result=getScore();
alert("Your score is "+ result +"/"+ 100);
 

//document.location.href = url;
}
