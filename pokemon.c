#include <stdio.h>
#include <string.h>
#define NAME_LEN 64
#define EXAM_LEN1 400
#define EXAM_LEN2 400


/*タイプのクラス*/
typedef struct type{
  char name[NAME_LEN];
  int  point;
  char exam1[EXAM_LEN1];
  char exam2[EXAM_LEN2];
} Type;

void swap_type(Type *x,Type *y){
  Type temp = *x;
  *x = *y;
  *y = temp;
}

/*タイプを初期化する */
Type type[] = {
  {"ノーマル",0,"マイペース","お主はこの世を普通に生きていきたいとおもっておる。あまり目立たずに平和に生きることも良いことじゃ。"},
  {"ほのお",0,"頑張り屋","お主は何事にも一生懸命に取り組む、とても素晴らしい情熱を持ったタイプじゃ！。素晴らしいことじゃが、休みを適度にとって自分を大切にする時間も必要じゃぞ。"},
  {"みず",0,"心がおおらか","お主は自分に起こる目の前の現象を受け入れ、水のごとく抵抗せずに流れるような生き方をしておる。もはや仙人のような心じゃのう"},
  {"くさ",0,"自然が好き","お主は自然を愛しておる。自分の生まれた場所を愛し、大切にする心はとても美しい。きっと心がきれいなんじゃな。"},
  {"でんき",0,"目立ちたがり屋","お主は人の目を魅了して何かすることが好きなタイプじゃのう、なーに、素直になりなさい。その心がパフォーマーとして生きたり、エンターテイナーとして活躍できたりするからのぅ。人を喜ばす才能を持っておるぞ！"},
  {"こおり",0,"ひかえめ","お主はあまり自分の主張をいうのが好きではないタイプじゃのう。それは人一倍人の意見を大切にしている謙虚さがあるという証拠じゃ！。じゃが自分を信じてあげることも重要じゃぞ。"},
  {"かくとう",0,"まじめ","お主はとても正義感にあふれ、曲がったことが嫌いなタイプじゃ！。お主のような人のおかげで今も誰かが守られているんじゃろうな。じゃが行き過ぎた正義感はアクにも変わる。自分の価値観を冷静に判断することも時には必要じゃ！"},
  {"どく",0,"おおちゃく","お主は色々な発想ができるクリエイティブな思考を持つタイプじゃ！。じゃが好奇心が行き過ぎると人を傷つけてしまうから注意じゃぞ！"},
  {"じめん",0,"スロースターター","お主はやり始めるのが遅いものの、ペースに乗るとものすごく集中するタイプじゃ！。出だしさえよければグループの中のリーダー的中心な人物になること間違い無しじゃ！"},
  {"ひこう",0,"自由奔放","お主は型にはまったことが嫌いなタイプじゃ！。じゃからこそ今の常識を常に疑い、自分がどう生きたいかに素直であり、自分の幸せをつかむことができるんじゃろうな。簡単そうに見えてとても難しいことじゃ。"},
  {"エスパー",0,"頭脳明晰","お主は物事の本質、人の心理を見透かすことに卓越しておる。だからこそ悩めることも多いと思うのぅ。相談できる相手がいると楽になるじゃろうな。"},
  {"むし",0,"虫好き","お主は生き物が好きなタイプじゃ！。「生命」には終わりがある。「生命」というものについて興味があることは、生きる上でとても大切であり、自分の価値観を形成していくものじゃ。生きとし生ける物すべてに感謝して生きたいのぅ。"},
  {"いわ",0,"頑固","お主は自分を突き通す、人に流されないタイプじゃ！。よく漫画の主人公も自分の信念を突き通す性格をしておる。とてもかっこいい生き方をしておる。じゃが人の意見を大切に聞くことも時に重要じゃ。そこからまた自分で考えればいいだけじゃからのぅ。"},
  {"ゴースト",0,"嫉妬深い性格","お主は自分の欲に忠実なタイプじゃ！。だからこそ自分の持ちたいものを持っている人に嫉妬することが多いのぅ。でもそれは悪いことではない。嫉妬は今自分が本当にほしいものを教えてくれるからのぅ。嫉妬を上手く利用するのじゃ！。"},
  {"ドラゴン",0,"クール","お主は冷静に物事を判断し、落ち着いているタイプじゃ！。上手くいけばモテるタイプじゃのう。ただ意識しすぎると周りから痛いやつだと見られる可能性があるから注意じゃぞ！。"},
  {"あく",0,"いたずら好き","お主は面白いと思ったことをすぐに行動に移すタイプじゃ！。だからこそ多くの人を楽しませる才能があるのじゃが、少し間違うと迷惑をかけたり傷つけてしまうこともあるから注意じゃぞ！。"},
  {"はがね",0,"打たれ強い心の持ち主","お主はとても辛抱強く耐え、じっくり待ち、あとから成功するタイプじゃ！。じゃが溜め込んでいると急に折れてしまうことがある。辛かったら自分を守る選択も大事じゃぞ。"},
  {"フェアリー",0,"優しさあふれる性格","お主は人のことをよく考えてくれる人間であり、周りから好かれているタイプじゃ！。きっと今も救われている人が何人もいることじゃろうな。じゃが何かあった時自分を責める性格でもある。あまり自分を責めなくてええんじゃぞ！。"}
};

Type work[] = {
  {"ノーマル",0,"マイペース","お主はこの世を普通に生きていきたいとおもっておる。あまり目立たずに平和に生きることも良いことじゃ。"},
  {"ほのお",0,"頑張り屋","お主は何事にも一生懸命に取り組む、とても素晴らしい情熱を持ったタイプじゃ！。素晴らしいことじゃが、休みを適度にとって自分を大切にする時間も必要じゃぞ。"},
  {"みず",0,"心がおおらか","お主は自分に起こる目の前の現象を受け入れ、水のごとく抵抗せずに流れるような生き方をしておる。もはや仙人のような心じゃのう"},
  {"くさ",0,"自然が好き","お主は自然を愛しておる。自分の生まれた場所を愛し、大切にする心はとても美しい。きっと心がきれいなんじゃな。"},
  {"でんき",0,"目立ちたがり屋","お主は人の目を魅了して何かすることが好きなタイプじゃのう、なーに、素直になりなさい。その心がパフォーマーとして生きたり、エンターテイナーとして活躍できたりするからのぅ。人を喜ばす才能を持っておるぞ！"},
  {"こおり",0,"ひかえめ","お主はあまり自分の主張をいうのが好きではないタイプじゃのう。それは人一倍人の意見を大切にしている謙虚さがあるという証拠じゃ！。じゃが自分を信じてあげることも重要じゃぞ。"},
  {"かくとう",0,"まじめ","お主はとても正義感にあふれ、曲がったことが嫌いなタイプじゃ！。お主のような人のおかげで今も誰かが守られているんじゃろうな。じゃが行き過ぎた正義感はアクにも変わる。自分の価値観を冷静に判断することも時には必要じゃ！"},
  {"どく",0,"おおちゃく","お主は色々な発想ができるクリエイティブな思考を持つタイプじゃ！。じゃが好奇心が行き過ぎると人を傷つけてしまうから注意じゃぞ！"},
  {"じめん",0,"スロースターター","お主はやり始めるのが遅いものの、ペースに乗るとものすごく集中するタイプじゃ！。出だしさえよければグループの中のリーダー的中心な人物になること間違い無しじゃ！"},
  {"ひこう",0,"自由奔放","お主は型にはまったことが嫌いなタイプじゃ！。じゃからこそ今の常識を常に疑い、自分がどう生きたいかに素直であり、自分の幸せをつかむことができるんじゃろうな。簡単そうに見えてとても難しいことじゃ。"},
  {"エスパー",0,"頭脳明晰","お主は物事の本質、人の心理を見透かすことに卓越しておる。だからこそ悩めることも多いと思うのぅ。相談できる相手がいると楽になるじゃろうな。"},
  {"むし",0,"虫好き","お主は生き物が好きなタイプじゃ！。「生命」には終わりがある。「生命」というものについて興味があることは、生きる上でとても大切であり、自分の価値観を形成していくものじゃ。生きとし生ける物すべてに感謝して生きたいのぅ。"},
  {"いわ",0,"頑固","お主は自分を突き通す、人に流されないタイプじゃ！。よく漫画の主人公も自分の信念を突き通す性格をしておる。とてもかっこいい生き方をしておる。じゃが人の意見を大切に聞くことも時に重要じゃ。そこからまた自分で考えればいいだけじゃからのぅ。"},
  {"ゴースト",0,"嫉妬深い性格","お主は自分の欲に忠実なタイプじゃ！。だからこそ自分の持ちたいものを持っている人に嫉妬することが多いのぅ。でもそれは悪いことではない。嫉妬は今自分が本当にほしいものを教えてくれるからのぅ。嫉妬を上手く利用するのじゃ！。"},
  {"ドラゴン",0,"クール","お主は冷静に物事を判断し、落ち着いているタイプじゃ！。上手くいけばモテるタイプじゃのう。ただ意識しすぎると周りから痛いやつだと見られる可能性があるから注意じゃぞ！。"},
  {"あく",0,"いたずら好き","お主は面白いと思ったことをすぐに行動に移すタイプじゃ！。だからこそ多くの人を楽しませる才能があるのじゃが、少し間違うと迷惑をかけたり傷つけてしまうこともあるから注意じゃぞ！。"},
  {"はがね",0,"打たれ強い心の持ち主","お主はとても辛抱強く耐え、じっくり待ち、あとから成功するタイプじゃ！。じゃが溜め込んでいると急に折れてしまうことがある。辛かったら自分を守る選択も大事じゃぞ。"},
  {"フェアリー",0,"優しさあふれる性格","お主は人のことをよく考えてくれる人間であり、周りから好かれているタイプじゃ！。きっと今も救われている人が何人もいることじゃろうな。じゃが何かあった時自分を責める性格でもある。あまり自分を責めなくてええんじゃぞ！。"}

};

void merge_sort(int,int);

/*アンケート内容 */
void quest(){
  int no;
  printf("お〜よく来たのぅ、わしはオ-キドというものじゃ。\n");
  printf("これからきみのタイプについて調べるぞぉ〜！\n");
  printf("自分の心に従って素直に答えるのじゃ！\n");
  printf("「はい」なら数字の１を、「いいえ」なら数字の０を打ち込んでくれぃ。\n");
  printf("ではいくぞぉ！\n");


  printf("\n\n「あなたは正しいと言われている行動をするのがすきですか」\n");
  scanf("%d",&no);
  if (no == 1){
    printf("素晴らしいことじゃ！\n");
    add(&type[6],&work[6]);
    add(&type[6],&work[6]);
    add(&type[6],&work[6]);
    add(&type[4],&work[4]);
    add(&type[1],&work[1]);
    add(&type[16],&work[16]);
    add(&type[16],&work[16]);
    add(&type[16],&work[16]);
    add(&type[12],&work[12]);
    add(&type[12],&work[12]);
  }else{
    printf("別に今正しいと言われていることが正しいとは限らんからのぅ！\n");
    printf("気にすることはないぞ！\n");
    add(&type[15],&work[15]);
    add(&type[15],&work[15]);
    add(&type[15],&work[15]);
    add(&type[13],&work[13]);
    add(&type[7],&work[7]);
    add(&type[7],&work[7]);
  }

  printf("\n\n「正直自分あまり感情がないなと思うことがある」\n");
  scanf("%d",&no);
  if (no == 1){
    printf("ある意味自分の目の前のことを客観視することができるということじゃな！\n");
    add(&type[10],&work[10]);
    add(&type[10],&work[10]);
    add(&type[10],&work[10]);
    add(&type[2],&work[2]);
    add(&type[2],&work[2]);
    add(&type[7],&work[7]);
    add(&type[7],&work[7]);
    add(&type[16],&work[16]);
      add(&type[16],&work[16]);
    add(&type[12],&work[12]);
    add(&type[12],&work[12]);
  }else{
    printf("目の前のことを精一杯感じる心は大事じゃな！\n");
    add(&type[15],&work[15]);
    add(&type[15],&work[15]);
    add(&type[13],&work[13]);
    add(&type[13],&work[13]);
    add(&type[7],&work[7]);
    add(&type[7],&work[7]);
    add(&type[1],&work[1]);
    add(&type[1],&work[1]);
    add(&type[4],&work[4]);
    add(&type[4],&work[4]);
  }

  printf("\n\n「あなたはカブトムシがすきですか」\n");
  scanf("%d",&no);
  if (no == 1){
    printf("わしもよく小さい頃トランセルを孵化させていたのぅ\n");
    printf("じゃが大人になるほど虫が苦手になるのはなんでなんじゃろうな\n");
    add(&type[11],&work[11]);
    add(&type[11],&work[11]);
    add(&type[11],&work[11]);
    add(&type[3],&work[3]);
  }else{
    printf("蜘蛛とかムカデはまじでムリ\n");
    add(&type[10],&work[10]);
    add(&type[17],&work[17]);
  }

  printf("\n\n「恋愛はすきですか」\n");
  scanf("%d",&no);
  if (no == 1){
    printf("わしも若い頃は盛んだったのぅ！\n");
    printf("キクコも昔は良かったが、今では見る影もないがのぅ、、、\n");
    printf("あ、今の話しは無かったことにしてくれ、頼む\n");
    add(&type[1],&work[1]);
    add(&type[1],&work[1]);
    add(&type[1],&work[1]);
    add(&type[4],&work[4]);
    add(&type[17],&work[17]);
  }else{
    printf("色々あったんですね、お疲れ様です。\n");
    printf("別に恋愛は必要十分ではないとは思うが、一緒に過ごしたいと思う人ができるといいのぅ！\n");
    add(&type[7],&work[7]);
    add(&type[16],&work[16]);
    add(&type[2],&work[2]);
  }

  printf("\n\n「実力史上主義ですか？」\n");
  scanf("%d",&no);
  if (no == 1){
    printf("向上心があっていいのぅ！\n");
    printf("じゃが周りへの感謝を忘れてはならぬぞ\n");
    printf("一人で頑張ることは素晴らしいことじゃが、それゆえにそこに他の人が加わっていることを忘れてしまう\n");
    printf("一人でプログラミングを書いていたとしても、その前にｐｃやソフトウェアなど作ってくれた人たちがいるようにのぅ\n");
    add(&type[1],&work[1]);
    add(&type[16],&work[16]);
    add(&type[16],&work[16]);
    add(&type[12],&work[12]);
    add(&type[12],&work[12]);
    add(&type[14],&work[14]);
    add(&type[14],&work[14]);
  }else{
    printf("人と強調することも、自分を高めるのもバランスが大事じゃな\n");
    add(&type[5],&work[5]);
    add(&type[2],&work[2]);
    add(&type[0],&work[0]);
  }

  printf("\n\n「普通に生きていきたいですか？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("普通とは人によるが、今の自分が幸せであることに気づくと普通に幸せに生きれるとわしは思うのぅ！\n");
    add(&type[0],&work[0]);
    add(&type[0],&work[0]);
    add(&type[0],&work[0]);
    add(&type[12],&work[12]);
    add(&type[16],&work[16]);
    add(&type[2],&work[2]);
  }else{
    printf("ビックになるのが夢かのう！ええのぅ！\n");
    add(&type[14],&work[14]);
    add(&type[13],&work[13]);
    add(&type[9],&work[9]);
  }

  printf("\n\n「松岡修造は好きですか？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("おお！バシャーモが好きなんじゃのう！\n");
    add(&type[1],&work[1]);
    add(&type[1],&work[1]);
  }else{
  printf("もっと熱くなれよ\n");
    add(&type[2],&work[2]);
    add(&type[5],&work[5]);
    add(&type[3],&work[3]);
    add(&type[11],&work[11]);
  }

  printf("\n\n熱いよりは冷たいほうが好き\n");
  scanf("%d",&no);
  if (no == 1){
    add(&type[2],&work[2]);
    add(&type[2],&work[2]);
    add(&type[2],&work[2]);
    add(&type[5],&work[5]);
  }else{
    add(&type[1],&work[1]);
    add(&type[12],&work[12]);
    add(&type[8],&work[8]);
    add(&type[8],&work[8]);
  }

  printf("\n\n「日常会話でも「草ｗｗｗｗｗ」とか言ってしまう？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("言葉というのは時代によって変わるものだからしょうがないじゃろうな\n");
  printf("だからどんな言葉もなんと言われようがわしは使っていいと思うぞぉ！\n");
    add(&type[3],&work[3]);
    add(&type[3],&work[3]);
    add(&type[3],&work[3]);
    add(&type[11],&work[11]);

  }else{
  printf("草ｗｗｗｗｗ\n");
    add(&type[0],&work[0]);
    add(&type[14],&work[14]);
    add(&type[17],&work[17]);
  }

  printf("\n\n「雷怖い...」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("わしも怖い\n");
    add(&type[2],&work[2]);
    add(&type[9],&work[9]);
  }else{
    printf("お主は特性が「ひらいしん」かのう、、、\n");
    add(&type[4],&work[4]);
    add(&type[4],&work[4]);
    add(&type[4],&work[4]);
  }

  printf("\n\n「生まれ変わったら羽生結弦になりたいですか？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("かっこよくてクールじゃもんな、昔のわしのようじゃ\n");
    add(&type[5],&work[5]);
    add(&type[5],&work[5]);
    add(&type[5],&work[5]);
  }else{
    printf("人それぞれなりたいものは違うからのぅ！お主はお主でよいのじゃ！\n");
    add(&type[14],&work[14]);
    add(&type[8],&work[8]);
    add(&type[9],&work[9]);
  }

  printf("\n\n「格闘技を見たりしたりするのは好きですか？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("格闘技をみるだけで強くなった気分になるのはなんでじゃろうな\n");
    add(&type[6],&work[6]);
    add(&type[6],&work[6]);
    add(&type[6],&work[6]);
  }else{
    printf("もうあの頃のように血の気が多くはないのじゃ、、\n");
    add(&type[10],&work[10]);
    add(&type[12],&work[12]);
    add(&type[17],&work[17]);
  }

  printf("\n\n「自分でも少し毒舌なほうだと思う？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("難しいところじゃのう。関係の距離によっていいようにも悪いようにもなるからのぅ\n");
    add(&type[7],&work[7]);
    add(&type[7],&work[7]);
    add(&type[7],&work[7]);
    add(&type[13],&work[13]);
    add(&type[15],&work[15]);
  }else{
    printf("言うべきところは言うのじゃぞ！\n");
    add(&type[17],&work[17]);
  }

  printf("\n\n「体育のとき先生の話聞くの嫌で、ずっと地面に絵書いてた？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("悪い子すぎぃぃぃぃぃぃ！\n");
    add(&type[8],&work[8]);
    add(&type[8],&work[8]);
    add(&type[8],&work[8]);
    add(&type[15],&work[15]);
    add(&type[13],&work[13]);
  }else{
    printf("ええこじゃ！\n");
    add(&type[0],&work[0]);
    add(&type[5],&work[5]);
    add(&type[16],&work[16]);
    add(&type[6],&work[6]);
  }

  printf("\n\n「自由になりたい、、、、？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("色々お疲れ様じゃのう、、、\n");
    add(&type[9],&work[9]);
    add(&type[9],&work[9]);
    add(&type[9],&work[9]);
  }else{
    printf("多少不自由があるからこそ、自由を感じるのかもしれんのう\n");
    add(&type[6],&work[6]);
    add(&type[11],&work[11]);
    add(&type[3],&work[3]);
  }

  printf("\n\n「心理学は好きですか？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("大学の授業で心理学を学んでもモテないと聞いた時、落胆したのう、、、\n");
    add(&type[10],&work[10]);
    add(&type[10],&work[10]);
    add(&type[10],&work[10]);
    add(&type[13],&work[13]);
  }else{
    printf("それもまた良きじゃ\n");
    add(&type[0],&work[0]);
    add(&type[6],&work[6]);
    add(&type[13],&work[13]);
  }

  printf("\n\n「あんまり体を動かさないほう？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("最近太りましたという声が多いのじゃ！！！\n");
    add(&type[12],&work[12]);
    add(&type[12],&work[12]);
    add(&type[12],&work[12]);
    add(&type[16],&work[16]);
    add(&type[8],&work[8]);
  }else{
    printf("わしもランニングするか、、、\n");
    add(&type[4],&work[4]);
    add(&type[9],&work[9]);
  }

  printf("\n\n「、、、、陰キャ？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("そもそも陰キャとは何なんじゃろうな。あまり口数が少ない人でも話してみると面白い人もたくさんおる\n");
  printf("話したこともない人を暗そうだからという理由で陰キャと決めつける人の心の方こそ陰キャではないのかのぅ、、、\n");
    add(&type[13],&work[13]);
    add(&type[13],&work[13]);
    add(&type[13],&work[13]);
    add(&type[15],&work[15]);
    add(&type[5],&work[5]);
  }else{
    printf("明るく楽しくいきることは大事じゃな！\n");
    add(&type[1],&work[1]);
    add(&type[4],&work[4]);
    add(&type[6],&work[6]);
    add(&type[17],&work[17]);
  }

  printf("\n\n「正直自分はメンタルが強いと思う？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("良いことじゃのう！じゃが溜め込んではいかんぞ、ある日突然崩れるからのぅ！\n");
  printf("適度に気を抜いて、発散して生きるのじゃ！\n");
    add(&type[16],&work[16]);
    add(&type[16],&work[16]);
    add(&type[16],&work[16]);
    add(&type[12],&work[12]);
    add(&type[6],&work[6]);
    add(&type[2],&work[2]);
  }else{
    printf("自分の弱さを認めるのも１つの強さじゃ！\n");
    add(&type[5],&work[5]);
    add(&type[16],&work[16]);
    add(&type[10],&work[10]);
  }

  printf("\n\n「よく優しい人だと言われますか？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("お主のような人に何人もの人が救われておるだろうなぁ、感謝するぞ！\n");
    add(&type[17],&work[17]);
    add(&type[17],&work[17]);
    add(&type[17],&work[17]);
    add(&type[10],&work[10]);
    add(&type[10],&work[10]);
  }else{
    printf("自分の人生を生きておる証拠じゃ！\n");
    add(&type[14],&work[14]);
    add(&type[15],&work[15]);
  }

  printf("\n\n「中二病になったことはありますか？」\n");
  scanf("%d",&no);
  if (no == 1){
  printf("、、、一度は誰もが通る道じゃ！気にすることはないぞ、、、\n");
    add(&type[14],&work[14]);
    add(&type[14],&work[14]);
    add(&type[14],&work[14]);
    add(&type[10],&work[10]);
    add(&type[6],&work[6]);
  }else{
    printf("えぇ！？ポケモンマスターになりたいと思ったことはないのか、お主、、、\n");
    add(&type[10],&work[10]);
    add(&type[17],&work[17]);
  }





}

/*それぞれの構造体のナンバーを計算*/
void add(Type *ty,Type *wk){
  ty->point += 1;
  wk->point += 1;
}

// 分割
void divide(int mid, int left, int right) {
  merge_sort(left, mid);
  merge_sort(mid+1, right);
}

void print_array(){
  int i;
  printf("type[]={");
  for (i=0; i<18; i++) {
    if (i != 0) printf(",");
    printf("%d", type[i].point);
  }
  printf("}\n");
}

/*文字列表示（結果出力） */
void print_result(){
  int i;
  printf("\n\nお主のタイプは「");

  printf(type[17].name);
  printf(",");
  printf(type[16].name);

  printf("」じゃ！！。\n");

  printf("\n\nお主の性格は、");

  printf(type[17].exam1);
  printf("で、");
  printf(type[16].exam1);

  printf("であるのぅ！。\n\n");

  printf(type[17].exam2);
  printf("\n\nまた");
  printf(type[16].exam2);

  printf("\n\n逆にお主の嫌いなタイプは「");

  printf(type[0].name);
  printf(",");
  printf(type[1].name);
  printf(",");
  printf(type[2].name);

  printf("」じゃ！\n");

  printf("\n\nお主は残念ながら、");

  printf(type[0].exam1);
  printf("で,");
  printf(type[1].exam1);
  printf("で,");
  printf(type[2].exam1);

  printf("な性格の人と合わないかもしれんのぅ\n");
  printf("\nじゃが苦手な人は自分の持たない考え方をしていることが多く、そこから違う価値観を学べることもある。じゃが不快に思うこともあるじゃろう。関わるのも関わらないのもお主の自由じゃ。\n");
  printf("\n\n何？本来のポケモンと弱点であるタイプが違うじゃと？本来のポケモンという単語がそもそもわからぬのぅ、、、\n");
  printf("\n\nこれで診断は以上じゃ。みなもポケモンゲットじゃぞぉ〜！。\n");

}

void merge(int mid, int left, int right,Type a[]) {
  int i, j, k, m;
  // 統合
  // 統合：前処理：前半そのままコピー
  for (i = left; i <= mid; i++) {
    swap_type(&work[i],&a[i]);
  }
  // 統合：前処理：後半逆順コピー
  for (j = mid+1; j <= right; j++) {
    m = right+mid+1-j;
    swap_type(&work[m],&a[j]);
  }
  // 統合：本処理
  i = left;
  j = right;
  for (k = left; k <= right; k++) {
    if (work[i].point < work[j].point) {
      swap_type(&a[k],&work[i]);
      i++;
    } else {
      swap_type(&a[k],&work[j]);
      j--;
    }
  }
  return;
}

void merge_sort (int left, int right) {
  int mid;

  /* もし要素が一個 (left >= right) なら終了 (return) */
  if (left >= right) {
    return;
  }

  /* 列を分割する場所を決める */
  mid = (left + right)/2;

  /* 配列を分割してマージソートする (divide() 関数の利用) */
  divide(mid,left,right);
  /* 2つのソート済み領域を，マージしてソートする (merge() 関数の利用) */
  merge(mid,left,right,type);
  print_array();
}



int main(void) {
  quest();
  merge_sort(0, 17);
  print_result();
  return 0;
}
