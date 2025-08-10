// public class App {
//     public static void main(String[] args){
//         int testscore = 88;
//         char grade;
//         if (testscore >= 90){
//             grade = 'A';
//         }else if(testscore >= 80){
//             grade = 'B';
//         }else if(testscore >= 70){
//             grade = 'C';
//         }else if(testscore >= 60){
//             grade = 'D';
//         }else{
//             grade = 'F';
//         }
//         System.out.println("Grade = "+grade);
//     }
// }

// public class App {
//     public static void main(String[] args){
//         int month = 8;
//         switch(month){
//             case 1:System.out.println("一月");break;
//             case 2:System.out.println("二月");break;
//             case 3:System.out.println("三月");break;
//             case 4:System.out.println("四月");break;
//             case 5:System.out.println("五月");break;
//             case 6:System.out.println("六月");break;
//             case 7:System.out.println("七月");break;
//             case 8:System.out.println("八月");break;
//             case 9:System.out.println("九月");break;
//             case 10:System.out.println("十月");break;
//             case 11:System.out.println("十一月");break;
//             case 12:System.out.println("十二月");break;
//         }
//     }
// }

// public class App {
//     public static void main(String[] args){
//         String copyFromMe = "Copy this string until you encounter the litter 'u'.";
//         StringBuffer copyToMe = new StringBuffer();
//         int i = 0;
//         char c = copyFromMe.charAt(i);
//         while(c != 'u'){
//             copyToMe.append(c);
//             c = copyFromMe.charAt(++i);
//         }
//         System.out.println(copyToMe);
//     }
// }

// public class App{
//     public static void main(String[] args){
//         String copyFromMe = "Copy this string until you encounter the litter 'u'.";
//         StringBuffer copyToMe = new StringBuffer();
//         int i = 0;
//         char c = copyFromMe.charAt(i);
//         do{
//             copyToMe.append(c);
//             c = copyFromMe.charAt(++i);
//         }while(c != 'u');
//         System.out.println(copyToMe);
//     }
// }

// public class App{
//     public static void main(String[] args){
//         int[] array0fInts = {32,87,3,589,12,1076,2000,8,622,127};
//         int searchfor = 12;
//         int i = 0;
//         boolean foundIt = false;
//         for(i = 0; i < array0fInts.length; i++){
//             if(array0fInts[i] == searchfor){
//                 foundIt = true;
//                 break;
//             }
//         }
//         if(foundIt){
//             System.out.println("Found"+searchfor+"at index" + i);
//         }else{
//             System.out.println(searchfor+"not in the arrat");
//         }

//     }
// }

// public class App {
//     public static void main(String[ ] args) {
//     StringBuffer searchMe = new StringBuffer(
//     "peter piper picked a peck of pickled peppers");
//     int max = searchMe.length();
//     int numPs = 0;
//     for (int i = 0; i<max; i++){if(searchMe.charAt(i) != 'p')
//     continue;
//     numPs++;
//     searchMe. setCharAt(i,'P');
//     System. out. println("Found"+ numPs +"p's in the string.");
//     System. out.println(searchMe);
//     }
// }
// }

// public class App {
//     public static void main(String[] args) {
//         String searchMe = "Look for a substring in me";
//         String substring = "sub";
//         boolean foundIt = false;
//         int max = searchMe.length() - substring.length();
//         test: for (int i = 0; i <= max; i++) {
//             int n = substring.length();
//             int j = i;
//             int k = 0;
//             while (n-- != 0) {
//                 if (searchMe.charAt(j++) != substring.charAt(k++)) {
//                     continue test;
//                 }
//             }
//             foundIt = true;
//             break test;
//         }
//         System.out.println(foundIt ? "Found it" : "Didn't find it");
//     }
// }

// public class App {
//     public static void main(String[] args) {
//         int[] anArray;
//         anArray = new int[10];
//         for (int i = 0; i < anArray.length; i++) {
//             anArray[i] = i;
//             System.out.print(anArray[i] + "");
//         }
//         System.out.println();
//     }
// }

// public class App {
//     public static void main(String[] args) {
//         String[] anArray = { "String One", "String Two", "String Three" };
//         for (int i = 0; i < anArray.length; i++) {
//             System.out.println(anArray[i].toLowerCase());
//         }
//     }
// }

// public class App {
//     public static void main(String[] args) {
//         int[][] arrayOfInts = { { 32, 87, 3 },
//                 { 12, 1076, 2004, 8, 123 },
//                 { 622, 127, 77, 955 }
//         };
//         int searchfor = 12;
//         int i = 0, j = 0;
//         boolean foundIt = false;
//         search: for (i = 0; i < arrayOfInts.length; i++) {
//             for (j = 0; j < arrayOfInts[i].length; j++) {
//                 if (arrayOfInts[i][j] == searchfor) {
//                     foundIt = true;
//                     break search;
//                 }
//             }
//         }
//         if (foundIt) {
//             System.out.println("Found" + searchfor + " at " + i + "," + j);
//         } else {
//             System.out.println(searchfor + "not in the array");
//         }
//     }
// }

// public class App {
//     public static void main(String[] args) {
//         char[] copyFrom = { 'd', 'e', 'c', 'a', 'f', 'f', 'e', 'i', 'n', 'a', 't', 'e', 'd' };
//         char[] copyTo = new char[7];
//         System.arraycopy(copyFrom, 2, copyTo, 0, 7);
//         System.out.println(new String(copyTo));
//     }
// }

