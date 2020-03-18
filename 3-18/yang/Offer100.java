package com.ibuyi.interview.leetcode;

import java.util.HashMap;
import java.util.TreeSet;

public class Offer100 {
    /*
    每年，政府都会公布一万个最常见的婴儿名字和它们出现的频率，也就是同名婴儿的数量。有些名字有多种拼法，
    例如，John 和 Jon 本质上是相同的名字，但被当成了两个名字公布出来。给定两个列表，
    一个是名字及对应的频率，另一个是本质相同的名字对。设计一个算法打印出每个真实名字的实际频率。
    注意，如果 John 和 Jon 是相同的，并且 Jon 和 Johnny 相同，则 John 与 Johnny 也相同，即它们有传递和对称性。
    在结果列表中，选择字典序最小的名字作为真实名字。
    synonyms = ["(Jon,John)","(John,Johnny)","(Chris,Kris)","(Chris,Christopher)"]
     */
    public String[] trulyMostPopular(String[] names, String[] synonyms) {
        //创建一个hash表存储每个名字出现的次数
        HashMap<String,Integer> hs = new HashMap<>();
        //创建一个hash表，保存祖先
        HashMap<String,String> unionMap = new HashMap<>();
        //1.统计每个名字出现的频率
        for(String str:names){
            int index1 = str.indexOf("(");
            int index2 = str.indexOf(")");
            int num = Integer.valueOf(str.substring(index1+1,index2));
            hs.put(str.substring(0,index1),num);
        }

        //2.把名字组合分开，查看每个名字有没有祖先。
        for(String name:synonyms){
            int index = name.indexOf(",");
            String name1 =name.substring(1,index);
            String name2 =name.substring(index+1,name.length()-1);
            //判断这两个名字的祖先
            while(unionMap.containsKey(name1)){
                name1=unionMap.get(name1);
            }
            while(unionMap.containsKey(name2)){
                name2=unionMap.get(name2);
            }

            //如果name1等于name2,说明name1和name2对应的频次，已经被加到祖先上了
            if(!name1.equals(name2)){
                int num = hs.getOrDefault(name1,0)+hs.getOrDefault(name2,0);
                //按照字典序排序
                String truelyName = name1.compareTo(name2)<0?name1:name2;//存进unionMap中的祖先
                String errorName = name1.compareTo(name2)<0?name2:name1;//后面如果再发现errorName,则根据errorName找到他对应的祖先
                unionMap.put(errorName,truelyName);
                hs.remove(errorName);//为了保证后面可以正确获取到数组的大小
                hs.put(truelyName,num);
            }

        }
        String res[] = new String[hs.size()];
        int index=0;
        for(String name:hs.keySet()){
            StringBuilder sb = new StringBuilder();
            sb.append(name);
            sb.append("(");
            sb.append(hs.get(name));
            sb.append(")");
            res[index++]=sb.toString();


        }
        return res;
    }

}
