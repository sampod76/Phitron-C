// https://phitron.io/ph068/video/ph068-1_2-types-of-graph
/*
🔹 Graph এর প্রকারভেদ (Types of Graph)

এখানে ৩ভাবে গ্রাফকে ভাগ করা হয়েছে:

1️⃣ Direction অনুযায়ী (Direction)
✅ 1. Directed Graph (ডাইরেক্টেড গ্রাফ)

এখানে edge এর দিক থাকে (→)

মানে:
A → B মানে A থেকে B তে যাওয়া যাবে

কিন্তু B থেকে A তে যাওয়া যাবে না (যদি আলাদা edge না থাকে)

উদাহরণ:

YouTube subscriber

One way road

A → B
✅ 2. Undirected Graph (আনডাইরেক্টেড গ্রাফ)

এখানে edge এর কোন দিক নেই।

মানে:
A — B
A থেকে B যাওয়া যাবে
B থেকে A যাওয়া যাবে

উদাহরণ:

Friendship relation

Two way road

A — B
2️⃣ Weight অনুযায়ী (Weight)
✅ 1. Weighted Graph

এখানে edge এর সাথে একটি মান (weight) থাকে।

Weight হতে পারে:

Distance

Cost

Time

Strength

উদাহরণ:
ঢাকা → চট্টগ্রাম (২৫০ কিমি)

A --(10)--> B

(10 = weight)

✅ 2. Unweighted Graph

এখানে edge এর সাথে কোনো weight নেই।

শুধু সংযোগ আছে, মান নেই।

উদাহরণ:
Friendship graph

3️⃣ Cycle অনুযায়ী (Cycle)
✅ 1. Cyclic Graph

যদি গ্রাফে এমন কোনো পথ থাকে যেখানে শুরু node তে আবার ফিরে আসা যায়, তাহলে সেটি Cyclic।

উদাহরণ:

A → B → C → A

এখানে A তে আবার ফিরে আসা গেছে।
তাই এটা cyclic graph।

✅ 2. Acyclic Graph

যদি এমন কোনো cycle না থাকে, তাহলে সেটি acyclic।

উদাহরণ:

A → B → C

এখানে শুরুতে ফিরে আসা যাচ্ছে না।
তাই এটি acyclic।

🎯 সংক্ষেপে এক নজরে
Type	মানে
Directed	Edge এর দিক আছে
Undirected	Edge এর দিক নেই
Weighted	Edge এর মান আছে
Unweighted	Edge এর মান নেই
Cyclic	ঘুরে আবার শুরুতে ফেরা যায়
Acyclic	ঘুরে শুরুতে ফেরা যায় না
*/
/*
এই ছবিতে Graph কিভাবে কম্পিউটারে সংরক্ষণ (represent) করা হয় সেটা দেখানো হয়েছে।
তিনটি পদ্ধতি আছে:

✅ Adjacency Matrix:
গ্রাফকে 2D array দিয়ে রাখা হয়, যেখানে দুই node এর মধ্যে edge থাকলে 1 (বা weight) থাকে, না থাকলে 0 থাকে।
input 5 6 -> 5 First node + 6 edge/connecting

✅ Adjacency List:
প্রতিটি node এর সাথে যে যে node যুক্ত আছে তাদের একটি list আকারে রাখা হয়।

✅ Edge List:
গ্রাফের সব edge কে শুধু pair (u, v) বা (u, v, weight) আকারে সংরক্ষণ করা হয়।

এখন সহজ বাংলায় একদম পরিষ্কার করে বুঝাই
*/
