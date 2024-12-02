package interfaces;

public class Gaadi {
   private Engine engine;
   private Mediaplayer mediaplayer;

   public Gaadi() {
       engine = new Powerunit();
       mediaplayer = new Mediaplayer();
   }

   public Gaadi(Engine engine, Mediaplayer mediaplayer) {
       this.engine = engine;
       this.mediaplayer = mediaplayer;
   }

   public void start(){
       engine.start();
   }

   public void stop(){
       engine.stop();
   }

   public void accelerate(){
       engine.accelerate();
   }

   public void startMusic(){
       mediaplayer.start();
   }

   public void stopMusic(){
       mediaplayer.stop();
   }
}
