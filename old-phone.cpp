import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class BrokenCalculator {

    public static int ans = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt(), m = sc.nextInt(), o = sc.nextInt();
            ArrayList<Integer> workingNumber = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) {
                int num = sc.nextInt();
                workingNumber.add(num);
            }

            int signs[] = new int[4];
            for (int i = 0; i < m; i++) {
                int num = sc.nextInt();
                signs[num - 1] = 1;
            }

            int target = sc.nextInt();
            getMinSteps(target, new HashMap<Integer, Integer>(), 1, workingNumber, o, signs);
            System.out.println(ans);
        }
        sc.close();
    }

    public static void getMinSteps(int target, HashMap<Integer, Integer> output, int cur_level,
            ArrayList<Integer> workingNumber, int o, int[] signs) {

        if (workingNumber.size() == 0) {
            // System.out.println(output);
            return;
        }


        // 2 3
        // [1] 
        for (int i = 0; i < workingNumber.size(); i++) {
            int cur_ele = workingNumber.get(i);
            // System.out.println("Cuurent Number :" + cur_ele);
            // System.out.println("Output :" + output);
            workingNumber.remove(i);
            HashMap<Integer, Integer> new_output = new HashMap<>();
            new_output.put(cur_ele, 1);
            for (Map.Entry<Integer, Integer> entry : output.entrySet()) {
                int val = entry.getKey();
                int level = entry.getValue(); //touches -> lvel

                // add operation
                if (signs[0] == 1) {
                    int newAdd = cur_ele + val;
                    int newFreq = level + 3;
                    // System.out.println("Adding" + cur_ele + " + " + val + " = " + newAdd + " freq :" + newFreq);
                    if (!new_output.containsKey(newAdd)) {
                        new_output.put(newAdd, newFreq);
                    } else if (new_output.get(newAdd) > newFreq) {
                        new_output.put(newAdd, newFreq);
                    }
                    if (newAdd == target && newFreq <= o) {
                        ans = Math.min(ans, newFreq);
                    }
                }
                // minus
                if (signs[1] == 1) {
                    int newAdd = Math.abs(cur_ele - val);
                    int newFreq = level + 3;
                    // System.out.println("Substracting" + cur_ele + " - " + val + " = " + newAdd + " freq :" + newFreq);
                    if (!new_output.containsKey(newAdd)) {
                        new_output.put(newAdd, newFreq);
                    } else if (new_output.get(newAdd) > newFreq) {
                        new_output.put(newAdd, newFreq);
                    }
                    if (newAdd == target && newFreq <= o) {
                        ans = Math.min(ans, newFreq);
                    }
                }
                // multiply
                if (signs[2] == 1) {
                    int newAdd = cur_ele * val;
                    int newFreq = level + 3;
                    // System.out.println("Multiplying" + cur_ele + " * " + val + " = " + newAdd + " freq :" + newFreq);
                    if (!new_output.containsKey(newAdd)) {
                        new_output.put(newAdd, newFreq);
                    } else if (new_output.get(newAdd) > newFreq) {
                        new_output.put(newAdd, newFreq);
                    }
                    if (newAdd == target && newFreq <= o) {
                        ans = Math.min(ans, newFreq);
                    }
                }
                // divide
                if (signs[3] == 1) {
                    // System.out.println("Dividing" + cur_ele + " + " + val);
                    if (val != 0 && cur_ele >= val) {
                        if (cur_ele % val == 0) {
                            int newAdd = cur_ele / val;
                            int newFreq = level + 3;
                            if (!new_output.containsKey(newAdd)) {
                                new_output.put(newAdd, newFreq);
                            } else if (new_output.get(newAdd) > newFreq) {
                                new_output.put(newAdd, newFreq);
                            }
                            if (newAdd == target && newFreq <= o) {
                                ans = Math.min(ans, newFreq);
                            }
                        }
                    } else {
                        if (cur_ele != 0 && val % cur_ele == 0) {
                            int newAdd = val / cur_ele;
                            int newFreq = level + 3;
                            if (!new_output.containsKey(newAdd)) {
                                new_output.put(newAdd, newFreq);
                            } else if (new_output.get(newAdd) > newFreq) {
                                new_output.put(newAdd, newFreq);
                            }
                            if (newAdd == target && newFreq <= o) {
                                ans = Math.min(ans, newFreq);
                            }
                        }
                    }
                }
                // adding the original string
                String one = Integer.toString(cur_ele);
                String two = Integer.toString(val);
                int newAdd = Integer.parseInt(one.concat(two));
                int newFreq = level + 1;
                // System.out.println("Concat" + cur_ele + " + " + val + " freq :" + newFreq);
                if (!new_output.containsKey(newAdd)) {
                    new_output.put(newAdd, newFreq);
                } else if (new_output.get(newAdd) > newFreq) {
                    new_output.put(newAdd, newFreq);
                }
                if (newAdd == target && newFreq <= o) {
                    ans = Math.min(ans, newFreq);
                }
                // adding the reverse string
                newAdd = Integer.parseInt(two.concat(one));
                if (!new_output.containsKey(newAdd)) {
                    new_output.put(newAdd, newFreq);
                } else if (new_output.get(newAdd) > newFreq) {
                    new_output.put(newAdd, newFreq);
                }
                if (newAdd == target && newFreq <= o) {
                    ans = Math.min(ans, newFreq);
                }
            }
            for (Map.Entry<Integer, Integer> entry : output.entrySet()) {
                int val = entry.getKey();
                int level = entry.getValue();
                if (!new_output.containsKey(val)) {
                    new_output.put(val, level);
                } else {
                    if (new_output.get(val) > level) {
                        new_output.put(val, level);
                    }
                }
            }
            getMinSteps(target, new_output, cur_level + 1, workingNumber, o, signs);
            workingNumber.add(i, cur_ele);
        }

    }

}
