function solution(info, query) {
    var answer = [];
    let M = new Map();

    // 1. info 전처리
    for (let i = 0; i < info.length; i++) {
        let [lang, role, exp, soulfood, score] = info[i].split(' ').map(el => el.trim());
        score = parseInt(score);

        for (let a = 0; a < 2; a++) {
            for (let b = 0; b < 2; b++) {
                for (let c = 0; c < 2; c++) {
                    for (let d = 0; d < 2; d++) {
                        let key = [
                            a === 1 ? '-' : lang,
                            b === 1 ? '-' : role,
                            c === 1 ? '-' : exp,
                            d === 1 ? '-' : soulfood,
                        ].join(' ');

                        if (M.has(key)) {
                            M.get(key).push(score);
                        } else {
                            M.set(key, [score]);
                        }
                    }
                }
            }
        }
    }

    // 2. value 배열 정렬
    for (let arr of M.values()) {
        arr.sort((a, b) => a - b);
    }

    // 3. query 처리 (이분 탐색)
    for (let i = 0; i < query.length; i++) {
        let parts = query[i].replace(/ and /g, ' ').split(' ');
        let score = parseInt(parts.pop()); // 마지막이 점수
        let key = parts.join(' ');
        let count = 0;

        if (M.has(key)) {
            let arr = M.get(key);

            // lower bound (score 이상이 처음 나오는 인덱스 찾기)
            let left = 0, right = arr.length;
            while (left < right) {
                let mid = Math.floor((left + right) / 2);
                if (arr[mid] >= score) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            count = arr.length - left;
        }

        answer.push(count);
    }

    return answer;
}
