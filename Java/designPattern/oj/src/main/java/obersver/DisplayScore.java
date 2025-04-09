package obersver;

class DisplayScore implements  Observer{

    @Override

    public void update(String gameTime, int homeScore, int visitorScore) {

        System.out.println(String.format("%s:%d-%dscreenDisplay",gameTime,homeScore,visitorScore));

    }

}
