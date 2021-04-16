public class Testing{
    private static void printDebugInfo(ArrayList al){
        System.out.println(al.toString() + " | " + al.size() + " | " + al.capacity());
    }
    public static void main (String[] args){
        ArrayList al = new ArrayList();
        printDebugInfo(al);
        for(int i = 0; i < 100; i++){
            al.push_back(i);
        }
        printDebugInfo(al);
        while (al.size() > 10){
            al.pop_back();
            printDebugInfo(al);
        }

        for(int i = 0; i < 10; i++){
            al.set_at(i, i * 111);
        }
        printDebugInfo(al);

        for(int i = 0; i < al.size(); i++){
            System.out.println(al.get_at(i));
        }
        System.out.println("Inserting");
        printDebugInfo(al);
        al.insert(9, -1);
        printDebugInfo(al);

        for (int i = 0; i < al.size(); i++){
            al.set_at(i, 100);
        }
        printDebugInfo(al);



        // erase(int i)
        // erase(int i, length
        
        // insert()
        // capacity()
        // size()
        // push_back()
        // pop_back()
        // get_at()
        // reserve()
        // resize()
        // set_at()
    }
}