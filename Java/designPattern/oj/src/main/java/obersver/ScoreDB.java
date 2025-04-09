package obersver;

class ScoreDB implements  Observer{

    @Override

    public void update(String gameTime, int homeScore, int visitorScore) {

        System.out.println(String.format("%s:%d-%dwriteToDB",gameTime,homeScore,visitorScore));

    }

}