public class VektAdd implements Runnable{
  private int[] vek;
  private int[] vek2;
  public int result = 0;

  public VektAdd(int[] vek, int[] vek2){
    this.vek=vek;
    this.vek2=vek2;
  }

  public void run(){
    for(int i = 0; i < vek.length; i++){
      this.result = vek[i] * vek2[i] + result;
    }
  }
}

