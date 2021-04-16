public class ArrayList{
    private final int MIN_SIZE = 16;
    private int[] data = new int[0];
    private int size = 0;

    public ArrayList() {
    }

    public int size() {
        return this.size;
    }

    public int capacity() {
        if (data != null) {
            return data.length;
        } else return 0;
    }

    public boolean is_empty(){
        return this.size() == 0;
    }

    private boolean isValidIndex(int i) {
        if (i < 0 || i >= size) return false;
        else return true;
    }

    public int get_at(int i) throws ArrayIndexOutOfBoundsException {
        if (isValidIndex(i)) return data[i];
        else throw new ArrayIndexOutOfBoundsException(i);
    }

    public void reserve(int n) {
        n = Math.max(n, MIN_SIZE);
        if (capacity() < n) {
            int[] temp = new int[n];
            for (int i = 0; i < size; i++) {
                temp[i] = data[i];
            }
            for (int i = size; i < temp.length; i++) {
                temp[i] = 0;
            }
            data = temp;
        }
    }

    private void resize(int n) {
        if (n > capacity()) {
            int c = (int) (capacity() * 1.5);
            reserve(Math.max(n, c));
        } else if (n < size) {
            n = Math.max(0, n);
            for (int i = n; i < size; i++) {
                data[i] = 0;
            }
        }
        size = n;
    }

    public void push_back(int x) {
        int n = size;
        resize(n + 1);
        data[n] = x;
    }

    public void insert(int i, int x) throws ArrayIndexOutOfBoundsException {
        if (!isValidIndex(i)) throw new  ArrayIndexOutOfBoundsException(i);
        else {
            int n = size;
            resize(n + 1);

            for(int j = this.size() -1; j > i; j--){
                data[j] = data[j-1];
            }
            data[i] = x;
        }

    }

    public void pop_back() throws  ArrayIndexOutOfBoundsException {
        if (!isValidIndex(0)) throw new  ArrayIndexOutOfBoundsException(0);
        data[size - 1] = 0;
        size--;
    }

    public void erase(int i) throws  ArrayIndexOutOfBoundsException {
        if (!isValidIndex(i)) throw new  ArrayIndexOutOfBoundsException(i);
        else {
            for (int j = i; j < size; j++) {
                data[j] = data[j + 1];
            }
            size--;
            data[size] = 0;
        }
    }

    public void erase(int i, int length) throws ArrayIndexOutOfBoundsException{
        for(int j = i, x = 0; x < length; x++){ 
            if (!isValidIndex(j)){
                throw new ArrayIndexOutOfBoundsException(j);
            }
            this.erase(i);
        }
    }

    public void set_at(int i, int x) throws ArrayIndexOutOfBoundsException{
        if (!isValidIndex(i)) throw new ArrayIndexOutOfBoundsException(i);
        else this.data[i] = x;
    }

    @Override
    public String toString() {
        if (size > 0) {
            String temp = "[";
            for (int i = 0; i < size; i++) {
                temp += data[i] + ", ";
            }
            temp = temp.substring(0, temp.length() - 2) + "]";
            return temp;
        } else {
            return "[]";
        }
    }
}