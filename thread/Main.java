import java.util.Arrays;

public class Main {
  public static void main(String[] args ) throws InterruptedException  {
    int vek[][] = {{0, 1, 0, 0}, {0,0,1,0}, {0,0,0,1}, {1,0,0,0}};
    int vek2[] = {1,2,3,4};
    int result[] = new int[4];
    VektAdd[] vektAdd = new VektAdd[4];
    Thread[] myThread = new Thread[4];

    for(int i = 0; i < vek.length;i++){
      vektAdd[i] = new VektAdd(vek[i], vek2);
      myThread[i] = new Thread(vektAdd[i], "mTh");
      myThread[i].start();
    }

    for(int i = 0; i < vek.length;i++){
      myThread[i].join();
      result[i] = vektAdd[i].result;
    }

    System.out.println(Arrays.toString(result));

  }
}
