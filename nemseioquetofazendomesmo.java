interface Exp {
 void print();
 int eval();
}
class Add implements Exp {
 Exp left, right;
 Add (Exp l, Exp r) {
 left = l; right = r; }
 void print() {
 left.print();
 System.out.print("+");
 right.print();
 }
 int eval() {
 return left.eval()
 + right.eval();
 }
}
class Neg implements Exp {
 Exp expr;
 Neg (Exp e) { expr = e; }
 void print() {
 System.out.print("-(");
 expr.print();
 System.out.print(")");
 }
 int eval() {
 return expr.eval() * -1;
 }
} 
class Lit implements Exp {
 int value;
 Lit (int v) { value = v; }
 void print() {
 System.out.print(value);
 }
 int eval() { return value; }
}
class Test {
 Lit ltree;
 Add atree;
 Neg ntree;
 Test() {
 ltree = new Lit(3);
 atree = new Add(ltree, ltree);
 ntree = new Neg(ltree);
 }
 void run() {
 ltree.print();
 atree.print();
 ntree.print();
 System.out.println(ltree.eval());
 System.out.println(atree.eval());
 System.out.println(ntree.eval());
 }
} 