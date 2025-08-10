package t8;

import java.util.Arrays;
import java.util.List;

// 内容审核接口
interface ContentFilter {
    String filter(String content);
    void setNextFilter(ContentFilter nextFilter);
}

// 抽象审核过滤器
abstract class AbstractContentFilter implements ContentFilter {
    protected ContentFilter nextFilter;

    @Override
    public void setNextFilter(ContentFilter nextFilter) {
        this.nextFilter = nextFilter;
    }

    protected String passToNext(String content) {
        if (nextFilter != null) {
            return nextFilter.filter(content);
        }
        return content;
    }
}

// 具体审核过滤器 - 涉黄内容过滤
class PornographyFilter extends AbstractContentFilter {
    private List<String> pornKeywords = Arrays.asList("色情", "成人", "裸露");

    @Override
    public String filter(String content) {
        for (String keyword : pornKeywords) {
            if (content.contains(keyword)) {
                content = content.replace(keyword, "***");
            }
        }
        return passToNext(content);
    }
}

// 具体审核过滤器 - 广告内容过滤
class AdFilter extends AbstractContentFilter {
    private List<String> adKeywords = Arrays.asList("购买", "微信", "加群", "折扣");

    @Override
    public String filter(String content) {
        for (String keyword : adKeywords) {
            if (content.contains(keyword)) {
                content = content.replace(keyword, "###");
            }
        }
        return passToNext(content);
    }
}

// 具体审核过滤器 - 暴恐内容过滤
class ViolenceFilter extends AbstractContentFilter {
    private List<String> violenceKeywords = Arrays.asList("暴力", "恐怖", "枪械", "爆炸");

    @Override
    public String filter(String content) {
        for (String keyword : violenceKeywords) {
            if (content.contains(keyword)) {
                content = content.replace(keyword, "XXX");
            }
        }
        return passToNext(content);
    }
}

// 内容审核处理器
class ContentModeration {
    private ContentFilter filterChain;

    public ContentModeration() {
        // 构建责任链
        ContentFilter pornFilter = new PornographyFilter();
        ContentFilter adFilter = new AdFilter();
        ContentFilter violenceFilter = new ViolenceFilter();

        pornFilter.setNextFilter(adFilter);
        adFilter.setNextFilter(violenceFilter);

        this.filterChain = pornFilter;
    }

    public String processContent(String content) {
        System.out.println("原始内容: " + content);
        String filteredContent = filterChain.filter(content);
        System.out.println("审核后内容: " + filteredContent + "\n");
        return filteredContent;
    }
}

// 客户端使用
public class SocialMediaPlatform {
    public static void main(String[] args) {
        ContentModeration moderation = new ContentModeration();

        // 测试不同内容
        moderation.processContent("这是一个普通的内容，没有任何敏感词");

        moderation.processContent("这里有成人内容，请加微信群购买枪械");

        moderation.processContent("暴力视频展示爆炸场景，内含裸露画面");

        moderation.processContent("折扣优惠，快来购买吧");
    }
}