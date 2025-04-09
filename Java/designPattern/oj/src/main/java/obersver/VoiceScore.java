package obersver;

class VoiceScore implements  Observer{

    @Override

    public void update(String gameTime, int homeScore, int visitorScore) {

        System.out.println(String.format("%s:%d-%dvoice",gameTime,homeScore,visitorScore));

    }

}
